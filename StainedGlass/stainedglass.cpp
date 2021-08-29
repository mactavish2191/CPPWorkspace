
vector <sPoint> CImageProcessor::RemoveClosePoints(vector <sPoint> originalPoints, float minDistance, int width, int height)
{
	vector <sPoint> vettedPoints;
	int nPoints = originalPoints.size();

	sPoint cornerP;
	cornerP.x=0;
	cornerP.y=0;
	vettedPoints.push_back(cornerP);
	cornerP.x=width-1;
	cornerP.y=0;
	vettedPoints.push_back(cornerP);
	cornerP.x=width-1;
	cornerP.y=height-1;
	vettedPoints.push_back(cornerP);
	cornerP.x=0;
	cornerP.y=height-1;
	vettedPoints.push_back(cornerP);


	for (int i=0; i < nPoints; i++)
	{
		sPoint p = originalPoints.at(i);
		if ((p.x == 0 && p.y == 0) || (p.x==width-1 && p.y==0) | 
			(p.x == 0 && p.y == height-1) || (p.x==width-1 && p.y== height-1))
		{
			continue;
		}
		else
		{
			int tooClose = 0;
			for (int j=0; j < vettedPoints.size(); j++)
			{
				sPoint vetP = vettedPoints.at(j);
				double dX = vetP.x - p.x;
				double dY = vetP.y - p.y;
				double dist = sqrt(dX*dX + dY*dY);
				if (dist < minDistance)
				{
					tooClose=1;
					j=vettedPoints.size();
				}
			}
			if (tooClose == 0) vettedPoints.push_back(p);
		}
	}

	return vettedPoints;
}

void CImageProcessor::StainedGlass(Bitmap * pBitmap, float borderDensity, float imageDensity, float minDistance)
{
	
	int width = pBitmap->GetWidth();
	int height = pBitmap->GetHeight();

	vector <sPoint> originalPoints;

	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			int curRand = rand()%10000;
			float fRand = (float)curRand / 10000.0f;
			float density = imageDensity;
			if (j == 0 || i==0 || j == width-1 || i == height-1)
			{
				density = borderDensity;
			}
			if((j==0 && i==0) || (j==0 && i==height-1) ||
				(j==width-1 && i==0) || (j==width-1 && i==height-1))
			{
				density = 1000;	// put vertices in corner
			}

			if (fRand <= density)
			{
				sPoint curPoint;
				curPoint.x = j;
				curPoint.y = i;
				originalPoints.push_back(curPoint);
			}
		}
	}

	// It doesn't look good if points are too close together.
	// So we need to check and remove very close points
	originalPoints = RemoveClosePoints(originalPoints, minDistance, width, height);

	// allocate memory for points
	int nPoints = originalPoints.size();
	double *pDPoints = new double[nPoints*2];

	for (int i=0; i < nPoints; i++)
	{
		sPoint curPoint = originalPoints.at(i);
		pDPoints[i*2] = curPoint.x;
		pDPoints[i*2+1] = curPoint.y;
	}

	int nTriangles=0;
	int *pTriVert = NULL;
	
	// special note: dtris2 doesn't appear to work well. The triangulations it gives aren't always good, and are often times junk.
	// Perhaps there is an assumtion or requirement that the function has that hasn't been documented well?
	// Because this is for an artistic filter and time to code is short, I use the painfully slow points_delaunay_naive_2d.

	//int success = dtris2 ( nPoints, pDPoints, &nTriangles, pTriVert, pTriNabe );
	int success=0;
	pTriVert = points_delaunay_naive_2d ( nPoints, pDPoints, &nTriangles );

	unsigned long **ppColor = new unsigned long*[nTriangles];	// could've been a flattened array instead, but no matter.
	int *pPixelCount = new int[nTriangles];
	memset(pPixelCount, 0, sizeof(int)*nTriangles);
	for (int i=0; i < nTriangles; i++)
	{
		ppColor[i] = new unsigned long[3];		// r,g,b
		ppColor[i][0] = ppColor[i][1] = ppColor[i][2] = 0;
	}

	// for each pixel, for each triangle, see which triangle it's in.
#pragma omp parallel for shared(ppColor, pPixelCount)
	for (int y=0; y < height; y++)
	{
		for (int x=0; x < width; x++)
		{
			point p;
			p.x = (float)x;
			p.y = (float)y;

			for (int i=0; i < nTriangles; i++)
			{
				int v1 = pTriVert[i*3+0];
				int v2 = pTriVert[i*3+1];
				int v3 = pTriVert[i*3+2];

				point p0, p1, p2;
				p0.x = pDPoints[v1*2];
				p0.y = pDPoints[v1*2+1];
				p1.x = pDPoints[v2*2];
				p1.y = pDPoints[v2*2+1];
				p2.x = pDPoints[v3*2];
				p2.y = pDPoints[v3*2+1];

				int matched = IsPointInTriangle(p0, p1, p2, p);
				if (matched)
				{
					#pragma omp critical
					{
						Color color;
						// GetPixel is slow and using LockBits would be much faster, but I'm really going for simplicity here...
						pBitmap->GetPixel(x,y,&color);
						ppColor[i][0] += color.GetR();
						ppColor[i][1] += color.GetG();
						ppColor[i][2] += color.GetB();
						pPixelCount[i]++;
					}
					i=nTriangles;	// to exit;
				}
			}
		}
	}

	#pragma omp parallel for shared(ppColor)
	for (int i=0; i < nTriangles; i++)
	{
		if (pPixelCount[i])
		{
			ppColor[i][0] /= pPixelCount[i];
			ppColor[i][1] /= pPixelCount[i];
			ppColor[i][2] /= pPixelCount[i];
		}
		else
		{
			// extremely narrow and spread out triangles are possible where no pixels are fully in bounds.
			// just set it to black since it'll look like a line anyway
			ppColor[i][0] = ppColor[i][1] = ppColor[i][2] = 0;
		}
	}

	Graphics g(pBitmap);
	Pen pen(Color(0,0,0));

	for (int i=0; i < nTriangles; i++)
	{
		int v1 = pTriVert[i*3+0];
		int v2 = pTriVert[i*3+1];
		int v3 = pTriVert[i*3+2];

		Point p1((int)pDPoints[v1*2], (int)pDPoints[v1*2+1]);
		Point p2((int)pDPoints[v2*2], (int)pDPoints[v2*2+1]);
		Point p3((int)pDPoints[v3*2], (int)pDPoints[v3*2+1]);

		Point points[3];
		points[0] = p1;
		points[1] = p2;
		points[2] = p3;

		SolidBrush *brush = new SolidBrush(Color((BYTE)ppColor[i][0], (BYTE)ppColor[i][1], (BYTE)ppColor[i][2]));
		g.FillPolygon(brush, points, 3, Gdiplus::FillMode::FillModeAlternate);

		g.DrawLine(&pen, p1, p2);
		g.DrawLine(&pen, p2, p3);
		g.DrawLine(&pen, p3, p1);

		delete brush;
	}

	for (int i=0; i < nTriangles; i++) delete[] ppColor[i];
	delete[] ppColor;
	
	delete[] pDPoints;
	delete[] pTriVert;
}

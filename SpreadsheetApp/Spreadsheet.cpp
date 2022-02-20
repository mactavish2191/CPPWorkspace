#include "SpreadsheetCell.h"

class SpreadsheetApplication;
//using SCell = Spreadsheet::SpreadsheetCell; like typedef 

class Spreadsheet
{
public:
	Spreadsheet(const SpreadsheetApplication& theApp, int inWidth = kMaxWidth, int inHeight = kMaxHeight);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet& operator=(const Spreadsheet& rhs);
	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
	int getId() const;
	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;
	~Spreadsheet();

private:
	static int sCounter;
	int mId;
	void copyFrom(const Spreadsheet& src);
	bool inRange(int val, int upper);
	int mWidth, mHeight;
	const SpreadsheetApplication& mTheApp;
	SpreadsheetCell **mCells;
};
int Spreadsheet::sCounter;

int Spreadsheet::getId() const
{
	return sCounter;
}

void Spreadsheet::copyFrom(const Spreadsheet& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadsheetCell[mHeight];
	}
	for (size_t i = 0; i < mWidth; i++)
	{
		for (size_t j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

//Default Ctor
Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp, int inWidth, int inHeight) :mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth), mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight), mTheApp(theApp)
{
	mId = sCounter++;
	mCells = new SpreadsheetCell* [mWidth];
	for (size_t i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}
//Copy Ctor
Spreadsheet::Spreadsheet(const Spreadsheet& src):mTheApp(src.mTheApp)
{
	mId = sCounter++;
	copyFrom(src);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	//Check for self assignment
	if (this == &rhs)
	{
		return *this;
	}

	//Destroy previous heap memory
	for (size_t i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}

	delete[] mCells;
	mCells = nullptr;

	//Copy from rhs object
	copyFrom(rhs);

	return *this;
}

Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}

	delete[] mCells;
	mCells = nullptr;
}

bool Spreadsheet::inRange(int val, int upper)
{
	return (val <= upper) ? true : false;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
	if (!inRange(x, mWidth) || !(inRange(y, mHeight)))
	{
		throw std::out_of_range("Out of range");
	}
	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(int x, int y)
{
	if (!inRange(x, mWidth) || !(inRange(y, mHeight)))
	{
		throw std::out_of_range("Out of range");
	}
	return mCells[x][y];
}

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

int main() {
	fastio;
	float number = 0;
	cout << "Enter number :";
	cin >> number;


	auto start = chrono::steady_clock::now();
	float result = 1.0F / (sqrt(number));
	auto end = chrono::steady_clock::now();
	auto time_diff = end - start;
	

	// raw calculate
	cout << "Raw inverse square root: "<< result << "\n";
	cout << "Time :" << chrono::duration <double, milli> (time_diff).count() << " ms\n";

	start = chrono::steady_clock::now();
	cout << "Quake inverse square root: " << Q_rsqrt(number) << "\n";
	end = chrono::steady_clock::now();
	time_diff = end - start;
	cout << "Time :" << chrono::duration <double, milli> (time_diff).count() << " ms\n";



	return 0;
}



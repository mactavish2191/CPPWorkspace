#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>

using namespace std;

//---------------
//SpreadsheetCell::SpreadsheetCell() // old style constructor initialiazation
//{
//	mValue = 0;
//	mString = "";
//}


bool checkSpreadsheetCell(const SpreadsheetCell& cell)
{
    return !(cell.mString.empty());
}


//Default Ctor initializers
SpreadsheetCell::SpreadsheetCell():mValue(0)
{}
//Double Ctor
SpreadsheetCell::SpreadsheetCell(double initialValue)
{
	set(initialValue);
}

//String Ctor initializer
SpreadsheetCell::SpreadsheetCell(const string& initialValue):mValue(stringToDouble(initialValue)), mString(initialValue)
{ }

//Copy Ctor
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src):mValue(src.mValue), mString(src.mString)
{ }

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	mValue = rhs.mValue;
	mString = rhs.mString;
    return *this;
}

void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
	mString = doubleToString(inValue);
}

void SpreadsheetCell::set(const string& inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}


string SpreadsheetCell::doubleToString(double inValue)
{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const string& inString)
{
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if(istr.fail() || !istr.eof()){
		return 0;
	}
	return temp;
}
SpreadsheetCell operator+(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue + rhs.mValue);
    return newCell;
}
SpreadsheetCell operator-(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue - rhs.mValue);
    return newCell;
}
SpreadsheetCell operator*(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue * rhs.mValue);
    return newCell;
}
SpreadsheetCell operator/(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    if(rhs.mValue == 0)
        throw invalid_argument("Divide by zero");
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue / rhs.mValue);
    return newCell;
}
SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
    set(mValue + rhs.mValue);
    return *this;
}
SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
    set(mValue - rhs.mValue);
    return *this;
}
SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
    set(mValue * rhs.mValue);
    return *this;
}
SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
    if(rhs.mValue == 0)
        throw invalid_argument("Divide by zero");
    set(mValue / rhs.mValue);
    return *this;
}

bool operator==(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    return (lhs.mValue == rhs.mValue);
}
bool operator<(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    return (lhs.mValue < rhs.mValue);
}
bool operator>(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    return (lhs.mValue > rhs.mValue);
}
bool operator!=(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    return (lhs.mValue != rhs.mValue);
}
bool operator<=(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    return (lhs.mValue <= rhs.mValue);
}
bool operator>=(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs)
{
    return (lhs.mValue >= rhs.mValue);
}

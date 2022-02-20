#ifndef SPREADSHEETCELL_H_
#define SPREADSHEETCELL_H_
#include <string>

class SpreadsheetCell
{
	public:
		//friend class Spreadsheet; // All member function of Spreadsheet can access private & protected members of Spreadsheet
        //friend void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell); //friend function with Spreadsheet
        friend bool checkSpreadsheetCell(const SpreadsheetCell& cell);

		enum class Colors { Red = 1, Green, Blue, Yellow };
		void setColor(Colors color) { mColor = color; };
		SpreadsheetCell();  //Constructor
		//SpreadsheetCell() = default; //Compiler generated default constructor.
		//Implementation not needed.
		//SpreadsheetCell() = delete; If you dont want the compiler to generate a default ctor.
		SpreadsheetCell(double initialValue);
		explicit SpreadsheetCell(const std::string& initialValue);
		
		//---------------
		//Copy Constructor
		SpreadsheetCell(const SpreadsheetCell& src);
		//Explicitly defaulted or deleted copy constructor
		//SpreadsheetCell(const SpreadsheetCell& src) = default;
		//SpreadsheetCell(const SpreadsheetCell& src) = delete;
		//================

		//Asignment operator
		SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator+(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator-(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator*(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator/(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
    
        friend bool operator==(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend bool operator<(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend bool operator>(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend bool operator!=(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend bool operator<=(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
        friend bool operator>=(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
    
    
        SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
        SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
        SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
        SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
    
    
    
		//==================
		void set(double inValue); //setter double
		double getValue() const { mNumAccesses++; return mValue; }; //getter double
	
		void set(const std::string& inString); //setter string
		const std::string& getString() const { mNumAccesses++; return mString; }; //getter string
		
		static std::string doubleToString(double inValue); //double to string converter
		static double stringToDouble(const std::string& inString); //string to double converter
	private:
		
		Colors mColor = Colors::Red;
		double mValue;
		std::string mString;
		mutable int mNumAccesses = 0;
};



#endif

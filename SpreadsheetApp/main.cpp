#include "SpreadsheetCell.h"
#include <iostream>
#include <memory>
int main()
{
	SpreadsheetCell mycell(4), anothercell(5.6), mycellstr("test");
	mycell.setColor(SpreadsheetCell::Colors::Blue);
    SpreadsheetCell newcell = mycell + anothercell;
	//SpreadsheetCell* mycellp = new SpreadsheetCell();
	//auto mycellp = std::make_unique<SpreadsheetCell>(7.7);
	
	//mycellp->setValue(3.37);
	
	//std::cout <<"Cell 3: " << mycellp->getValue() << " " << mycellp->getString() << std::endl;
	//delete mycellp;
	//mycellp = nullptr;
	
	//mycell.setValue(6);
	//anothercell.setString("3.255");
	
	std::cout << "Cell 1: " << mycell.getValue() << std::endl;
	std::cout << "Cell 2: " << newcell.getValue() << std::endl;
	std::cout << "Cell 3: " << mycellstr.getValue() <<"  "<< mycellstr.getString() << std::endl;
	
	std::cin.get();
	return 0;
}

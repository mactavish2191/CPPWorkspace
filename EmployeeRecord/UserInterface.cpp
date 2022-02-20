//
//  UserInterface.cpp
//  EmployeeRecord
//
//  Created by Tavish on 7/17/16.
//  Copyright © 2016 Tavish. All rights reserved.
//

#include <iostream> 
#include <stdexcept> 
#include <exception>
#include "Database.hpp"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int displayMenu()
{
    int selection = 0;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1. Hire a new Employee." << endl;
    cout << "2. Fire an Employee." << endl;
    cout << "3. Promote an Employee." << endl;
    cout << "4. List all employees." << endl;
    cout << "5. List all current employees." << endl;
    cout << "6. List all former employees." << endl;
    cout << "0. Quit."<< endl;
    cout << endl;
    cout <<"---> ";
    cin >> selection;
    return selection;
    
}

void doHire(Database& db)
{
    string firstname = "";
    string lastname = "";
    cout << "First Name :";
    cin >> firstname;
    cout << "Last Name :";
    cin >> lastname;
    try {
        db.addEmployee(firstname, lastname);
    } catch (const std::exception& exception) {
        cerr << "Unable to add new employee :" << exception.what() << endl;
    }
}

void doFire(Database& db)
{
    int employeeNumber = 0;
    cout << "Employee Number :";
    cin >> employeeNumber;
    
    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch (const std::exception& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db)
{
    int employeeNumber = 0;
    int raiseAmount = 0;
    cout << "Employee Number :";
    cin >> employeeNumber;
    cout << "How much of a raise :";
    cin >> raiseAmount;
    
    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
        
    } catch (const std::exception& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}

void doDemote(Database& db)
{
    int employeeNumber = 0;
    int demeritAmount = 0;
    cout << "Employee Number :";
    cin >> employeeNumber;
    cout << "How much of a decrease :";
    cin >> demeritAmount;
    
    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.demote(demeritAmount);
        
    } catch (const std::exception& exception) {
        cerr << "Unable to demote employee: " << exception.what() << endl;
    }
}


int main()
{
    Database employeedb;
    bool done = false;
    
    while (!done) {
        int selection = displayMenu();
        
        switch (selection) {
            case 1:
                doHire(employeedb);
                break;
            case 2:
                doFire(employeedb);
                break;
            case 3:
                doPromote(employeedb);
                break;
            case 4:
                employeedb.displayAll();
                break;
            case 5:
                employeedb.displayCurrent();
                break;
            case 6:
                employeedb.displayFormer();
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
                break;
        }
    }
    
    
    return 0;
}
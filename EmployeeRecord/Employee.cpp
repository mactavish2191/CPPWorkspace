//
//  Employee.cpp
//  EmployeeRecord
//
//  Created by Tavish on 7/16/16.
//  Copyright © 2016 Tavish. All rights reserved.
//

#include <iostream>
#include "Employee.h"

namespace Records {
    Employee::Employee():_firstName(""),_lastName(""),_employeeNumber(-1),_salary(kDefaultStartingSalary),_hired(false)
    {}
    
    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }
    
    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }
    
    void Employee::hire()
    {
        _hired = true;
    }
    
    void Employee::fire()
    {
        _hired = false;
    }
    
    void Employee::display() const
    {
        std::cout << "Employee :" <<getLasttName()<<" ," <<getFirstName() << std::endl;
        std::cout << "---------------------------------" <<std::endl;
        std::cout << (_hired? "Current Employee" : "Former Employee") << std::endl;
        std::cout << "Employee Number: " << getEmployeeNumber() << std::endl;
        std::cout << "Salary: $" << getSalary() << std::endl;
        std::cout <<"\n";
    }
    
    //getters & setters
    void Employee::setFirstName(const std::string& firstName)
    {
        _firstName = firstName;
    }
    const std::string& Employee::getFirstName() const
    {
        return _firstName;
    }
    
    void Employee::setLastName(const std::string& lasttName)
    {
        _lastName = lasttName;
    }
    const std::string& Employee::getLasttName() const
    {
        return _lastName;
    }
    
    void Employee::setEmployeeNumber(int employeeNumber)
    {
        _employeeNumber = employeeNumber;
    }
    int Employee::getEmployeeNumber() const
    {
        return _employeeNumber;
    }
    
    void Employee::setSalary(int newSalary)
    {
        _salary = newSalary;
    }
    int Employee::getSalary() const
    {
        return _salary;
    }
    
    bool Employee::getIsHired() const
    {
        return _hired;
    }
    
}

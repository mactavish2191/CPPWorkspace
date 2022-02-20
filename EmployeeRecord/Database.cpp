//
//  Database.cpp
//  EmployeeRecord
//
//  Created by Tavish on 7/17/16.
//  Copyright © 2016 Tavish. All rights reserved.
//

#include "Database.hpp"
#include <iostream>
#include <stdexcept>

namespace Records {
    
    Database::Database():_nextEmployeeNumber(kFirstEmployeeNumber)
    {
        
    }
    
    Employee& Database::addEmployee(const std::string &firstName, const std::string &lastName)
    {
        Employee theEmployee;
        theEmployee.setFirstName(firstName);
        theEmployee.setLastName(lastName);
        theEmployee.setEmployeeNumber(_nextEmployeeNumber++);
        theEmployee.hire();
        _employees.push_back(theEmployee);
        return _employees[_employees.size() - 1];
        
    }
    
    Employee& Database::getEmployee(int employeeNumber)
    {
        for(auto& employee : _employees)
        {
            if (employee.getEmployeeNumber() == employeeNumber) {
                return employee;
            }
        }
        
        throw std::runtime_error("No Employee found.");
    }
    
    Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName)
    {
        for(auto& employee : _employees)
        {
            if (employee.getFirstName() == firstName && employee.getLasttName() == lastName) {
                return employee;
            }
        }
        
        throw std::runtime_error("No Employee found.");
    }
    
    void Database::displayAll() const
    {
        for (auto& employee : _employees) {
            employee.display();
        }
    }
    
    void Database::displayCurrent() const
    {
        for (auto& employee : _employees) {
            if(employee.getIsHired())
                employee.display();
        }
    }
    
    void Database::displayFormer() const
    {
        for (auto& employee : _employees) {
            if(!employee.getIsHired())
                employee.display();
        }
    }
    
    
}

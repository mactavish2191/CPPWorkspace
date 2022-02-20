//
//  Database.hpp
//  EmployeeRecord
//
//  Created by Tavish on 7/17/16.
//  Copyright © 2016 Tavish. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
    const int kFirstEmployeeNumber = 1000;
    
    class Database{
        
    public:
        Database();
        
        Employee& addEmployee(const std::string& firstName, const std::string& lastName);
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(const std::string& firstName, const std::string& lastName);
        
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;
        
    private:
        std::vector<Employee> _employees;
        int _nextEmployeeNumber;
    };
    
}

#endif /* Database_hpp */

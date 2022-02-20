//
//  Employee.h
//  EmployeeRecord
//
//  Created by Tavish on 7/16/16.
//  Copyright © 2016 Tavish. All rights reserved.
//

#ifndef Employee_h
#define Employee_h
#include <string>

namespace Records {
    
    const int kDefaultStartingSalary = 30000;
    
    class Employee{
    public:
        Employee();
        void promote(int raiseAmount = 1000);
        void demote(int demeritAmount = 1000);
        void hire();
        void fire();
        void display() const;
        
        //getters & setters
        
        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;
        
        void setLastName(const std::string& lasttName);
        const std::string& getLasttName() const;
        
        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;
        
        void setSalary(int newSalary);
        int getSalary() const;
        
        bool getIsHired() const;
        
    private:
        std::string _firstName;
        std::string _lastName;
        int _employeeNumber;
        int _salary;
        bool _hired;
    };
}


#endif /* Employee_h */

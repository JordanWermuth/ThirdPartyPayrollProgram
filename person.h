//
// Created by Jordan wermuth on 2019-03-04.
//

#ifndef INC_301ASSIGNMENT3_PERSON_H
#define INC_301ASSIGNMENT3_PERSON_H

#endif //INC_301ASSIGNMENT3_PERSON_H

//begin person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string firstName;
    string lastName;
    int employeeID;
    string companyName;
    float  hoursWorked;
    float  payRate;

public:
    Person();
    void   setFirstName(string fname);
    string getFirstName();
    void   setLastName(string lname);
    string getLastName();
    void   setEmployeeId(int Id);
    int    getEmployeeId();
    void   setCompanyName(string cname);
    string getCompanyName();
    void   setPayRate(float payrate);
    float  getPayRate();
    void   setHoursWorked(float hr);
    float  getHoursWorked();
    float  totalPay();
    string fullName();
};
#endif // end person.h


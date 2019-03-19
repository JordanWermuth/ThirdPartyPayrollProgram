//
// Created by Jordan wermuth on 2019-03-04.
//

#include "person.h"
#include <string>





Person::Person()
{

}

void Person::setFirstName(string fname)
{
    this -> firstName = fname;

}

string Person::getFirstName()
{
    return firstName;
}

void Person::setLastName(string lname)

{
    this -> lastName = lname;
}

string Person::getLastName()

{
    return lastName;
}

void Person::setEmployeeId(int Id)
{

    employeeID = Id;

}

int Person::getEmployeeId()
{
    return employeeID;

}


void Person::setCompanyName(string cname)
{
    companyName = cname;


}
string Person::getCompanyName()
{

    return companyName;

}
void Person::setPayRate(float rate)
{

    this->payRate = rate;

}
float Person::getPayRate()
{
    return payRate;

}
void Person::setHoursWorked(float hr)
{
    this -> hoursWorked = hr;

}
float Person::getHoursWorked()
{

    return hoursWorked;

}
float Person::totalPay()
{

    return hoursWorked * payRate;

}

string Person::fullName()
{

    return firstName + " " +lastName;

}


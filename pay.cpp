

#include "person.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


void readData(vector<Person> &emptyVec);
void getCompanies(vector<Person> &emptyVec,vector<string> &companyNames);
void printHighestPaid(vector<Person> &emptyVec);
void separateAndSave(vector<Person> &emptyVec, vector<string> &companyNames);

int main()

{

    vector<Person>employees;
    vector<string>companyNames;


    readData(employees);
    getCompanies(employees, companyNames);
    printHighestPaid(employees);
    separateAndSave(employees, companyNames);
    return 0;

}

void readData(vector<Person> &emptyVec)

{
    Person r;
    //string line;
    string fname;
    string lname;
    string cname;
    int Id;
    float hr;
    float rate;

    fstream inwardFile;
    inwardFile.open("input.txt");
    //check for an error in opening

    if(inwardFile.fail())
    {
        cout << "Could not open the file" << endl;
    }
      else
        {
            while(inwardFile >> fname >> lname >> Id >> cname >> hr >> rate)

            {

                Person r;
                r.setFirstName(fname);
                r.setLastName(lname);
                r.setEmployeeId(Id);
                r.setCompanyName(cname);
                r.setHoursWorked(hr);
                r.setPayRate(rate);
                emptyVec.push_back(fname + " " + lname + " " + Id + " " + cname + " " + hr + " " + rate);
            }
            inwardFile.close();

        }

}

void getCompanies(vector<Person> &emptyVec, vector<string> &companyName)

{

    for( int i = 0; i < emptyVec.size(); i++)

    {
        if( !(find(companyName.begin(), companyName.end(), emptyVec.at(i).getCompanyName()) != companyName.end() ))
            {
                companyName.push_back(emptyVec.at(i).getCompanyName());
            }

    }

}

void printHighestPaid(vector<Person>&emptyVec)

{
    int count = 0;
    int Id;
    string cname;
    string emptyname;
    float total;

    cout << showpoint;

    for (unsigned int i = 0; i < emptyVec.size(); i++)

    {
        if (count < emptyVec.at(i).totalPay())
        {
            count = emptyVec.at(i).totalPay();
            Id = emptyVec.at(i).getEmployeeId();
            cname = emptyVec.at(i).getCompanyName();
            emptyname = emptyVec.at(i).fullName();
            total = emptyVec.at(i).totalPay();
        }

    }


        cout << "Highest Paid: " << emptyname << endl;
        cout << "Employee ID: " << Id << endl;
        cout << "Company: " << cname << endl;
        cout << "Total Pay: $ " << total << endl;


}

void separateAndSave(vector<Person>&emptyVec,vector<string> &companyName)

{
    string name;
    for (unsigned int i = 0; i < emptyVec.size(); i++)
    {
        float totalpay = 0;
        name = companyName.at(i);

        fstream outputTxt(companyName.at(i) + ".txt");
        ifstream inwardFile;

        outputTxt << "Company: " << companyName.at(i) << ".txt" << endl;
        outputTxt << "_________________________" << endl;

        for (unsigned int i = 0; i < emptyVec.size() - 1; i++)
        {
            if (name == emptyVec.at(i).getCompanyName())
            {
                outputTxt << showpoint;
                outputTxt << setw(30) << left << emptyVec.at(i).fullName()<< " " << setw(30) << right <<
                          emptyVec.at(i).getEmployeeId() << " " << right << setw(30) << emptyVec.at(i).getCompanyName()
                          << " " << right << setw(30) << "$" << emptyVec.at(i).totalPay() << endl;

                totalpay += emptyVec.at(i).totalPay();
            }
        }
        outputTxt << "Total Pay: $ " << totalpay;
        outputTxt.close();


    }


}





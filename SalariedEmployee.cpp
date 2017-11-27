#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(int employeeNumber, string name, string address, string phone, double salary)
{
    this->employeeNumber = employeeNumber;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->salary = salary;
}

SalariedEmployee SalariedEmployee::read(ifstream& attachedFile)
{
    SalariedEmployee myHourlyEmployee = new SalariedEmployee;
    myHourlyEmployee.readData(attachedFile);
    return myHourlyEmployee&;
}

void readData(ifstream& attachedFile)
{
    string errorString;
    string dataString;
    
    if(!attachedFile.is_open())
    {
        errorString = "\nThe ifstream file is not open.\n";
        throw EmployeeException(errorString);
    }
    if(!attachedFile.good())
    {
        errorString = "\nThe ifstream file is not good.\n";
        throw EmployeeException(errorString);
    }
    
    this->Employee::readData();

    getline(attachedFile, dataString);
    this->salary = stod(dataString);
}

void write(ofstream& attachedFile)
{
    string errorString;
    if(!attachedFile.good())
    {
        errorString = "\nUnable to write to file.\n";
        throw EmployeeException(errorString);
    }
    
    this->Employee::write(attachedFile);
    
    attachedFile << this->salary << deliminingChar;
}

void printCheck()
{
    this->Employee::printCheck();
    
    cout << "Salary: " << fixed << setprecision(2);
    cout << "Salary: " << fixed << setprecision(2) << this->salary << endl << endl << endl << endl << endl;
}

double Employee::calcPay()
{
    double benifitCost;
    double federalTax;
    double stateTax;
    double netPay;
    
    federalTax = this->salary * federalTaxPercent / 100;
    stateTax = this->salary * stateTaxPercent / 100;
    benifitCost = this->salary * benifitCostPercent / 100;
    
    netPay = this->salary - federalTax - stateTax - benifitCost;
    
    return netPay;
}
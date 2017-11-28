#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(int employeeNumber, string name, string address, string phone, double weeklyHoursWorked, double hourlyWage) : Employee(employeeNumber, name, address, phone)
{
    this->weeklyHoursWorked = weeklyHoursWorked;
    this->hourlyWage = hourlyWage;
}

HourlyEmployee* HourlyEmployee::read(ifstream& attachedFile)
{
    HourlyEmployee myHourlyEmployee = new HourlyEmployee;
    myHourlyEmployee.readData(attachedFile);
    return myHourlyEmployee&;
}

void HourlyEmployee::readData(ifstream& attachedFile)
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
    
    stringbuf sb;
    
    attachedFile.get(sb, delimitingChar);
    this->hourlyWage = sb.str();
    attachedFile.ignore();  //Ignores delimiting character

    getline(attachedFile, dataString);
    this->weeklyHoursWorked = stod(dataString);
}

void HourlyEmployee::write(ofstream& attachedFile)
{
    string errorString;
    if(!attachedFile.good())
    {
        errorString = "\nUnable to write to file.\n";
        throw EmployeeException(errorString);
    }
    
    this->Employee::write(attachedFile);
    
    attachedFile << this->hourlyWage << delimitingChar;
    attachedFile << this->weeklyHoursWorked << endl;
}

void HourlyEmployee::printCheck()
{
    this->Employee::printCheck();
    
    cout << "Hours worked: " << fixed << setprecision(2) << this->weeklyHoursWorked << endl;
    cout << "Hourly wage: " << this->hourlyWage << endl << endl << endl << endl << endl;
}

double HourlyEmployee::calcPay()
{
    double grossPay;
    double federalTax;
    double stateTax;
    double netPay;

    if(this->weeklyHoursWorked <= overTimeHours)
    {
        grossPay = this->weeklyHoursWorked * this->hourlyWage;
    } else {
        grossPay = (overTimeHours * hourlyWage) + ((this->weeklyHoursWorked - overTimeHours) * hourlyWage * overTimeScaler);
    }
    
    federalTax = grossPay * federalTaxPercent / 100;
    stateTax = grossPay * stateTaxPercent / 100;
    
    netPay = grossPay - federalTax - stateTax;
    
    return netPay;
}
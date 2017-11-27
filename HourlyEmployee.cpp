#include "HourlyEmployee.h"


HourlyEmployee HourlyEmployee::read(ifstream& attachedFile)
{
    HourlyEmployee myHourlyEmployee = new HourlyEmployee;
    myHourlyEmployee.readData(attachedFile);
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
    
    stringbuf sb;
    
    attachedFile.get(sb, delimitningChar);
    this->hourlyWage = sb.str();
    attachedFile.ignore();  //Ignores delimiting character

    getline(attachedFile, dataString);
    this->weeklyHoursWorked = stod(dataString);
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
    
    attachedFile << this->hourlyWage << deliminingChar;
    attachedFile << this->weeklyHoursWorked << endl;
}

void printCheck()
{
    this->Employee::printCheck();
    
    cout << "Hours worked: " << fixed << setprecision(2) << this->weeklyHoursWorked << endl;
    cout << "Hourly wage: " << this->hourlyWage << endl << endl << endl << endl << endl;
}

double Employee::calcPay()
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
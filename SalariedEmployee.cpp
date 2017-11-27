#include "SalariedEmployee.h"

SalariedEmployee SalariedEmployee::read(ifstream& attachedFile)
{
    SalariedEmployee myHourlyEmployee = new SalariedEmployee;
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
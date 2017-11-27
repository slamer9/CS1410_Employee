#include "Employee.h"

//char deliminingChar =  '|'; // ***10.5, line is located elseware in later projects.

void Employee::setName(string setN)
{
    this->name = setN;
}

void Employee::setAddress(string setA)
{
    this->address = setA;
}

void Employee::setPhone(string setP)
{
    this->phone = setP;
}

int Employee::getEmployeeNumber()
{
    return this->employeeNumber;
}

string Employee::getName()
{
    return this->name;
}

string Employee::getAddress()
{
    return this->address;
}

string Employee::getPhone()
{
    return this->phone;
}

void Employee::write(ofstream& attachedFile)    //***12.8
{
    attachedFile << this->employeeNumber << deliminingChar;
    attachedFile << this->name << deliminingChar;
    attachedFile << this->address << deliminingChar;
    attachedFile << this->phone << deliminingChar;
}

// double Employee::calcPay()                      //***12.8
// {
//     //FIX ME
//     //COMPLETE FUNCTION
// }

void Employee::printCheck()                     //***12.8
{
    cout << endl << endl << endl;
    cout << "....................UVU Computer Science Dept................................." << endl << endl << endl;
    cout << "Pay to the order of " << this->name << "....................................$" << fixed << setprecision(2) << this->calcPay() << endl << endl << endl; //IS "this->calcPay()" A VALID CALL?
    cout << "United Community Credit Union" << endl << ".............................................................................." << endl << endl;
}

void Employee::readData(ifstream& attachedFile)
{
    stringbuf sb;
    
    attachedFile.get(sb, delimitningChar);
    this->employeeNumber = stoi(sb.str());
    attachedFile.ignore();  //Ignores delimiting character
    
    attachedFile.get(sb, delimitningChar);
    this->name = sb.str();
    attachedFile.ignore();  //Ignores delimiting character
    
    attachedFile.get(sb, delimitningChar);
    this->address = sb.str();
    attachedFile.ignore();  //Ignores delimiting character
    
    attachedFile.get(sb, delimitningChar);
    this->phone = sb.str();
    attachedFile.ignore();  //Ignores delimiting character
}


//*************************EXCEPTION CLASS********************
EmployeeException::EmployeeException(string myString)
{
    this->errorDetails = myString;
}



/************* OLD CODE ****************************************************************************  10.5

Employee::Employee(int cEmployeeNumber, double cHourlyWage, double cWeeklyHoursWorked, string cName, string cAddress, string cPhone) : (employeeNumber(cEmployeeNumber), hourlyWage(cHourlyWage), weeklyHoursWorked(cWeeklyHoursWorked), name(cName), addres(cAddress), phone(cPhone) {}

Employee Employee::read(ifstream& attachedFile)     ***10.5
{
    string errorString;
    string employeeDataString;
    
    int employeeNumberT;
    double hourlyWageT;
    double weeklyHoursWorkedT;
    string nameT;
    string addressT;
    string phoneT;
    
    if(!attachedFile.is_open())
    {
        errorString = "\nThe ifstream file not open.\n";
        throw EmployeeException(errorString);
    }
    if(!attachedFile.good())
    {
        errorString = "\nThe ifstream file not good.\n";
        throw EmployeeException(errorString);
    }
    getline(attachedFile, employeeDataString);

    //Pase data into meaningful pieces.
    //int start = 0;
    int position;
    
    position = employeeDataString.find(deliminingChar);
    employeeNumberT = stoi(employeeDataString.substr(0, position));     //Employee number
    employeeDataString.erase(0, position+1);
    
    position = employeeDataString.find(deliminingChar);
    hourlyWageT = stod(employeeDataString.substr(0, position));         //Hourly wage
    employeeDataString.erase(0, position+1);
    
    position = employeeDataString.find(deliminingChar);
    weeklyHoursWorkedT = stod(employeeDataString.substr(0, position));  //Weekly hours worked
    employeeDataString.erase(0, position+1);
    
    position = employeeDataString.find(deliminingChar);
    nameT = employeeDataString.substr(0, position);                     //Name
    employeeDataString.erase(0, position+1);
    
    position = employeeDataString.find(deliminingChar);
    addressT = employeeDataString.substr(0, position);                  //Adress
    employeeDataString.erase(0, position+1);
    
    position = employeeDataString.find(deliminingChar);
    phoneT = employeeDataString.substr(0, position);                    //Phone
    employeeDataString.erase(0, position+1);                            
    
    Employee returnEmployee(employeeNumberT, hourlyWageT, weeklyHoursWorkedT, nameT, addressT, phoneT);
    return returnEmployee;
}


Employee::Employee(int cEmployeeNumber, double cHourlyWage, double cWeeklyHoursWorked, string cName, string cAddress, string cPhone)
{
    this->employeeNumber = cEmployeeNumber;
    this->hourlyWage = cHourlyWage;
    this->weeklyHoursWorked = cWeeklyHoursWorked;
    this->name = cName;
    this->address = cAddress;
    this->phone = cPhone;
}

void Employee::setHourlyWage(double setH)
{
    this->hourlyWage = setH;
}

void Employee::setWeeklyHoursWorked(double setW)
{
    this->weeklyHoursWorked = setW;
}

double Employee::getHourlyWage()
{
    return this->hourlyWage;
}

double Employee::getWeeklyHoursWorked()
{
    return this->weeklyHoursWorked;
}

void Employee::write(ofstream& attachedFile)        //***10.5
{
    string errorString;
    
    attachedFile << this->employeeNumber << deliminingChar;
    attachedFile << this->hourlyWage << deliminingChar;
    attachedFile << this->weeklyHoursWorked << deliminingChar;
    attachedFile << this->name << deliminingChar;
    attachedFile << this->address << deliminingChar;
    attachedFile << this->phone << deliminingChar << endl;
    
    if(!attachedFile.good())
    {
        errorString = "\nUnable to write to file.\n";
        throw EmployeeException(errorString);
    }
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

void Employee::printCheck()
{
    cout << endl << endl << endl;
    cout << "....................UVU Computer Science Dept................................." << endl << endl << endl;
    cout << "Pay to the order of " << this->name << "....................................$" << fixed << setprecision(2) << this->calcPay() << endl << endl << endl; //IS "this->calcPay()" A VALID CALL?
    cout << "United Community Credit Union" << endl << ".............................................................................." << endl << endl;
    cout << "Hours worked: " << fixed << setprecision(2) << this->weeklyHoursWorked << endl;
    cout << "Hourly wage: " << this->hourlyWage << endl << endl << endl << endl << endl;
}
*/
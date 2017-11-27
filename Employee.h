#ifndef  Employee_header
#define  Employee_header

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream> //String stream
#include <stdexcept>
#include <exception>
//#include <vector>     //#include <cstring>    //#include <algorithm>// std::sort    //#include <unistd.h> //sleep();      //#include <limits>

using namespace std;

#define overTimeScaler 1.5
#define overTimeHours 40
#define federalTaxPercent 20
#define stateTaxPercent   7.5
#define benifitCostPercent 5.24
#define delimitningChar '|'

class Employee
{
   public:
      //static Employee read(ifstream&);  //Build an employee object reading from a file.   *****10.5
      ///Employee(int cEmployeeNumber, double cHourlyWage, double cWeeklyHoursWorked, string cName, string cAddress, string cPhone);   *****10.5
      
      virtual ~Employee();
      
      int    getEmployeeNumber();         //Gets data members.
      string getName();
      string getAddress();
      string getPhone();
      
      void   setName(string setN);        //Changes data members.
      void   setAddress(string setA);     //
      void   setPhone(string setP);       //
      
      virtual void   write(ofstream&);    //Writes Employee data to a file.
      virtual double calcPay();
      virtual void printCheck();
      
   protected:
      Employee() = default;
      Employee(int employeeNumber, string name, string address, string phone);
      void readData(ifstream&);
   
   private:
      int    employeeNumber;
      string name;
      string address;
      string phone;
      //int    numAttribues = 6; // CHANGE IF NUMBER OF PRIVATE DATA POINTS CHANGES         *****10.5
};



//*****10.5*****
class EmployeeException : public exception
{
   public:
      EmployeeException(string myString);
      
      virtual const char* what() const throw()  //DON'T KNOW WHAT THIS LINE DOES OTHER THAN ACCESSES THE what() FUNCTION OF STANDARD EXCEPTION CLASS
      {
         return errorDetails.c_str();
      }
      
   private:
      string errorDetails;
};

#endif
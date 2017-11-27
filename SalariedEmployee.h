#ifndef  SalariedEmployee_header
#define  SalariedEmployee_header

#include "Employee.h"

class SalariedEmployee : public Employee
{
    public:
        //SalariedEmployee();
        
        void   setSalary(double setS);
        double getSalary();

        void   write(ofstream&);
        double calcPay();
        void   printCheck();
        
        static SalariedEmployee read(ifstream&);
        
    protected:
        SalariedEmployee() = default;
        void readData(ifstream&);
    private:
        double salary;
};

#endif
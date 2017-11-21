#include "Employee.h"

class HourlyEmployee :: Employee
{
    public:
        HourlyEmployee();
        
        void setHourlyWage(double setH);
        void setWeeklyHoursWorked(double setW);
        double getHourlyWage();
        double getWeeklyHoursWorked();
        
        void write(ofstream&);
        double calcPay();
        void printCheck();
        
        static HourlyEmployee read(ifstream&);
    protected:
        HourlyEmployee() = default;
        void readData(ifstream&);
    private:
        double hourlyWage;
        double weeklyHoursWorked;
}
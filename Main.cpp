/*
DUNCAN REEVES, Nov 26 - Nov 27, 2017: CHAPTER 12 PROJECT
*/
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"


//Global variable declaration
string instructionString1 = "\n\nThis program has two options:\n1 - Create a data file, or\n2 - Read data from a file and print paychecks." \
                            "\nPlease enter (1) to create a file or (2) to print checks:\n";


int main()
{
    //MAIN VARIABLE DECLARATION
    int selection;
    bool firstInputGood;
    string fileName;
    ofstream userFileOStream;
    ifstream userFileIFstream;
    
    vector<Employee*> employeeList;
    try
    {
        firstInputGood = false;
        selection = 0;
        fileName = "";
        
        cout << instructionString1;
        while(!firstInputGood)  //Get first input
        {
            cin >> selection;
            if(cin.fail())
            {
                cout << "Invalid input, enter a \'1\' or a \'2\'." << endl;
            } else if(cin.eof())
            {
                throw runtime_error("End of file reached, exiting program.");
            } else if(cin.bad())
            {
                throw runtime_error("Failure, bad input stream.");
            } else if(cin.good())
            {
                if(selection == 1 || selection == 2)
                {
                    firstInputGood = true;
                } else
                {
                    cout << "Invalid input, enter a \'1\' or a \'2\'." << endl;
                }
            }
            else
            {
                //cout << "ERROR IN FILE: " << __FILE__ << ", LINE: " __LINE__ << endl;
                throw runtime_error("Aborting program.");
            }
        }
        
        cout << "Please enter a file name: ";
        cin >> fileName;
        if(selection == 1)  //RUN OPTION 1 ********************************* 
        {
            if(debugging == true) //Debugging    ****************************
            {
                cout << "\nThis is your fileName: " << fileName << endl;
            }
            
            userFileOStream.open(fileName);
            
            HourlyEmployee   harry(1, "H. Potter", "Privet Drive", "201-9090", 40, 12.00);
            SalariedEmployee alvis(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200);
            HourlyEmployee   ron(3, "R. Weasley", "The Burrow", "892-2000", 40, 10.00);
            SalariedEmployee rubius(4, "R. Hagrid", "Hogwarts", "910-8765", 1000);
            
            employeeList.push_back(harry&);
            employeeList.push_back(alvis&);
            employeeList.push_back(ron&);
            employeeList.push_back(rubius&);
            
            for(int i = 0; i < employeeList.size(); i++)
            {
                (employeeList.at(i)).write(userFileOStream);
            }
            
            cout << "Data file created ... you can now run option 2." << endl;
        } else if (selection == 2)  //RUN OPTION 2 ************************* READ
        {
            if(debugging == true) //Debugging    ****************************
            {
                cout << "\nThis is your fileName: " << fileName << endl;
            }
            
            userFileIFstream.open(fileName);
            
            Employee* Employee1 = Employee::read(userFileIFstream);
            Employee* Employee2 = Employee::read(userFileIFstream);
            Employee* Employee3 = Employee::read(userFileIFstream);
            Employee* Employee4 = Employee::read(userFileIFstream);
            
            employeeList.clear();
            employeeList.push_back(Employee1);
            employeeList.push_back(Employee2);
            employeeList.push_back(Employee3);
            employeeList.push_back(Employee4);
            
            for(int i = 0; i < employeeList.size(); i++)
            {
                (employeeList.at(i)).printCheck();
            }
            
        } else {
            //cout << "ERROR IN FILE: " << __FILE__ << ", LINE: " __LINE__ << endl << "NOW EXITING." << endl;   ***************************!
            //Throw program ending exception
        }
    }
    catch(EmployeeException& e) //CATCH PROGRAM ENDING ERROR
    {
        cout << endl << e.what() << endl;
    }
    catch (runtime_error& e)
    {
        cout << endl << e.what() << endl;
    }
    catch(...)
    {
        cout << "Caught something abnormal, \"catch(...)\"." << endl;
    }
}

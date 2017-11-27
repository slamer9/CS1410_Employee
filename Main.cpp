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
    try
    {
        firstInputGood = false;
        selection = 0;
        fileName = "";
        
        cout << instructionString1;
        while(!firstInputGood)
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
        if(selection == 1)  //RUN OPTION 1 ********************************* WRITE
        {
            cout << "\nThis is your fileName: " << fileName << endl; //Debugging    ****************************
            
            userFileOStream.open(fileName);
            
            Employee joe(37, 10.00, 45.00, "Joe Brown", "123 Main St.", "123-6788");
            Employee sam(21, 12.00, 30.00, "Sam Jones", "45 East State", "661-9000");
            Employee mary(15, 15.00, 40.00, "Mary Smith", "12 High Street", "401-8900");
            
            joe.write(userFileOStream);
            sam.write(userFileOStream);
            mary.write(userFileOStream);
            
            cout << "Data file created ... you can now run option 2." << endl;
        } else if (selection == 2)  //RUN OPTION 2 ************************* READ
        {
            cout << "\nThis is your fileName: " << fileName << endl; //Debugging    ****************************
            
            userFileIFstream.open(fileName);
            
            Employee Employee1 = Employee::read(userFileIFstream);
            Employee Employee2 = Employee::read(userFileIFstream);
            Employee Employee3 = Employee::read(userFileIFstream);
            
            Employee1.printCheck();
            Employee2.printCheck();
            Employee3.printCheck();
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

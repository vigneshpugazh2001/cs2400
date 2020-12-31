/*
 *        File: tickets.cc
 *      Author: Vignesh Pugazhenthi
 *        Date: 10/9/2020
 * Description: this program allows the user to deterimne whether the license number they input has violations or fines, the information is based off of a text file "violations.txt"
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

/**
 * isValid
 * determines if users input is matches the correct amount of letters and digits
 * 
 * @param license
 * @return returns users input if it's valid or not
 */ 
string isValid(string license);
/**
 * upperCase
 * capitalizes the first to letters of the users input
 * 
 * @param license
 * @return returns correct version of the users input
 */ 
string upperCase(string license);
/**
 * getFine
 * determines if the users input returns a fine
 * 
 * @param ins
 * @param revisedLicense
 * @param violation
 * @param totalfines
 * @return returns a fine
 */ 
void getFine(ifstream &ins, string revisedLicense, int &violation, double &totalfines);
/**
 * getResults
 * prints results of the users input using previous functions, number of violations and fines
 * 
 * @param revisedLicense
 * @param checkValid
 * @param violation
 * @param totalfines
 * @return returns printed data of the users input along with violations and fines
 */ 
string getResults(string revisedLicense, string checkValid, int Violation, double totalfines);
// function prototypes


int main(int argc, char const *argv[]) {
//declaration of variables
ifstream inStream;
string input;
string license;
int violation;
double totalfines;
//user inputs txt name
cout << "Enter the data file name: "<< endl;
cin >> input;
//open stream
if (input == "violations.txt")
{
    inStream.open("violations.txt");
}
else
{
    cout << "File name" << input << " does not exist.";
    exit(0);
}

//user enters license number once txt is successful
cout << "Enter a license number: ";
cin >> license;
//program then goes through each function chronologically to print result
string checkValid = isValid(license);
string revisedLicense = upperCase(license);
getFine(inStream, revisedLicense, violation, totalfines);
string finalresults = getResults(revisedLicense, checkValid, violation, totalfines);
cout << finalresults;
//program figures out if license has 6 or more violations
if (violation >= 6)
{
    cout << "\nLicense " + revisedLicense + " should be suspended" << endl;
}

cout << "\nTotal fine: $" << totalfines << endl;
//close stream
inStream.close();
return 0;
}  

//actual function code

string isValid(string license)
{
    if (license.length() == 8 
    && isalpha(license.at(0)) 
    && isalpha(license.at(1)) 
    && isdigit(license.at(2)) 
    && isdigit(license.at(3)) 
    && isdigit(license.at(4)) 
    && isdigit(license.at(5)) 
    && isdigit(license.at(6)) 
    && isdigit(license.at(7)))
    {
        return " is a valid license number.";
    }
    else
        return " is an invalid license number.";
}



string upperCase(string license){
for (int i = 0; i <= 2;)
{
    license.at(i) = toupper(license.at(i));
    i++;
}
return license;
}

void getFine(ifstream &ins, string revisedLicense, int &violation, double &totalfines)
{
    string licensenumber;
    int count;
    double sum = 0;
    double fine;
    while (!ins.eof())
    {
        ins >> licensenumber >> fine;
        if (licensenumber == revisedLicense)
        {
            count++;
            sum += fine;
        }
    }
if (sum == 0)
{
    count = 0;
}
totalfines = sum;
violation = count;
}

string getResults(string revisedLicense, string checkValid, int violation, double totalfines)
{
    string numberviolations = to_string(violation);
    string totfin = to_string(totalfines);
    if (isValid(revisedLicense) == " is a valid license number.")
    {
        cout << fixed << setprecision(2) << totfin << endl;
        return revisedLicense + checkValid + " \nNumber of violations: " + numberviolations;
    }
    else
    {
        return revisedLicense + checkValid;
    }
    
}
/*
 *        File: 03-hw-zipcode.cc
 *      Author: Vignesh Pugazhenthi
 *        Date: 9/30/2020
 * Description: This program allows the user to input a 5 digit zipcode and outputs barcodes based on the numbers the user input
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
#include <cmath>

using namespace std;
///function protypes

/**
 * getDigitCode
 * calculates the users input and returns a barcode
 * 
 * @param digit
 * @return a bar code
 */ 
string getDigitCode(char digit);

/**
 * getCheckDigitValue
 * this function checks the digit from the users input
 * 
 * @param sum
 * @return the check digit value
 */
int getCheckDigitValue(int sum);

/**
 * barcode
 * translates users input to check if sum if divisible by then returns barcodes in order from users input
 * 
 * @param sum
 * @return the users input into a barcode while checking if it's valid
 */
string barcode(int sum);

///main code

int main(int argc, char const *argv[]) {
///declarations    
int zipcode, checkdigitvalue, BARcode, barCode;
string choice;
///do while loop that allows the user to go through the program more than once if they choose to
do {
cout << "Enter a zipcode: " << endl;
cin >> zipcode;
///if statement that determines if users input is a valid zipcode
if(zipcode > 0){
    checkdigitvalue = getCheckDigitValue (zipcode);
    string barCode = getDigitCode(zipcode);
    string BARcode = barcode(zipcode);
    cout << "\n" << checkdigitvalue;
    cout << "\n" << barCode;
    cout << "\n" << BARcode; 
}

else{
    cout << "Error";
}
 return 0;

if (barCode == '-' ){
    cout << "Code is invalid";
}

    cout << "\n" << "More codes (y/n)? ";
    cin >> choice;
}
while (choice == "y");


return 0;


} 

//after main (function code)

string getDigitCode(char digit){
    
    if (digit == 0) return " ||::: ";
    if (digit == 1) return " :::|| ";
    if (digit == 2) return " ::|:| ";
    if (digit == 3) return " ::||: ";
    if (digit == 4) return " :|::| ";
    if (digit == 5) return " :|:|: ";
    if (digit == 6) return " :||:: ";
    if (digit == 7) return " |:::| ";
    if (digit == 8) return " |::|: ";
    if (digit == 9) return " |:|:: ";
    else return "";
}

int getCheckDigitValue (int sum){
    int sumdigits = 0;
    int checkdigitvalue;
    while (sum){
        sumdigits = sumdigits + sum % 10;
        sum = sum / 10;
    }
    checkdigitvalue = 10 - (sumdigits % 10);
    return checkdigitvalue;
}

string barcode(int sum){
    int checkdigitvalue = getCheckDigitValue(sum);
    int valueOne, valueTwo, valueThree, valueFour, valueFive;
    valueOne = sum % 10;
    sum = sum / 10;
    valueTwo = sum % 10;
    sum = sum / 10;
    valueThree = sum % 10;
    sum = sum / 10;
    valueFour = sum % 10;
    sum = sum / 10;
    valueFive = sum % 10;
    sum = sum / 10;
    string first = getDigitCode(valueOne) + getDigitCode(valueTwo) + getDigitCode(valueThree) + getDigitCode(valueFour) + getDigitCode (valueFive);
    string last = getDigitCode(checkdigitvalue);
    return (first + last);
}
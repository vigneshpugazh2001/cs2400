/*
 *        File: invoice.cc
 *      Author: Vignesh Pugazhenthi
 *        Date: 9/21/2020
 * Description: This program allows the user to determine the amount of words and sentences are written by the user.
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

///function prototypes

int main(int argc, char const *argv[]) {

string input;
int wordcounter = 0;
double totalwords = wordcounter;
int sentencecounter = 0;
double averagecounter;
char lastletter;
int length;

cout << "Enter a paragraph...";

do {

  
  wordcounter++;
  cin >> input;
  length = input.length();
  lastletter = input.at(length - 1);
  
  
  

if (lastletter == '.' || lastletter == '!' || lastletter == '?')
{
  sentencecounter++;
  
}


}
while (input != "@@@");

if (input == "@@@")
{
  totalwords = wordcounter - 1;
}

if (totalwords == '0' && sentencecounter == '0')
{
  cout << "You did not enter any text!";
}

else (totalwords >= '0' && sentencecounter =='0');
{
  cout << "You did not enter a sentence!" << "\n";
}

cout << fixed << setprecision(1) << endl;
cout << "word count: " << totalwords << "\n";
cout << "sentence count: "<< sentencecounter << endl;
averagecounter = totalwords / sentencecounter;
cout << "average words per sentence: " << averagecounter << endl;

}  
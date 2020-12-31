/**
 *   @file: book.library
 * @author: Vignesh Pugazhenthi
 *   @date: 12/3/2020
 *  @brief: this file is the main file for book-library
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "book.h"
using namespace std;

/**
 * authorSearch
 * if the users input matches the author on bookDB it prints it into the terminal
 * 
 * @param find- users input,  choice - vector
 * @return none
 */ 
void authorSearch (string find, vector <Book> &choice);

/**
 * titleSearch
 * if the users input matches the title on bookDB it prints it into the terminal
 * 
 * @param find- users input, choice - vector
 * @return none
 */ 
void titleSearch (string find, vector <Book> &choice);

/**
 * yearSearch
 * if the users input matches the search on bookDB it prints it into the terminal
 * 
 * @param find- user input, choice - vector
 * @return none
 */ 
void yearSearch (string find, vector <Book> &choice);

/**
 * bookAdd
 * if the users input matches the author on bookDB it prints it into the terminal
 * 
 * @param find, choice- vector, out- outstream
 * @return none
 */ 
void bookAdd (string find, vector <Book> &choice, ofstream &out);

/**
 * bookDelete
 * if the users input matches the author on bookDB it deletes it from bookDB.txt
 * 
 * @param find, choice- vector, out-outstream, ins-instream
 * @return none
 */ 
void bookDelete (string find, vector <Book> &choice, ofstream &out, ifstream &ins);

/**
 * noneOption
 * if the users input matches the match function from book.cc it prints it into the terminal
 * 
 * @param find-users input, choice-vector
 * @return none
 */ 
void noneOption (string find, vector <Book> &choice);

/**
 * indexOfsmallest
 * finds the position of the smallest year
 * 
 * @param find-users input, choice-vector, startIndex-starting position, endIndex-ending position
 * @return minIndex
 */ 
int indexOfsmallest(vector <Book> &choice, int startIndex, size_t endIndex);

/**
 * sortYear
 * uses indexOfsmallest and sorts the year by numerical order
 * 
 * @param choice-users input
 * @return none
 */ 
void sortYear(vector <Book> &choice);

int main(int argc, char const *argv[]) {
ifstream ins; 
ofstream out;
string option; 
string arg;
string find;

if (argc < 2 || argc > 3) //if argument is less than 2 or greater than 3
{
    cout << "Number of arguments is less than 2 or more than 3" << endl; //cout this
    exit(0);
}

if (argc == 2) //if argument counter equals 2
{
    find = argv[1]; //option equals first argument variable
} else {
    arg = argv[1]; //arg equals first argument variable
    find = argv[2]; //find equals second argument variable
}

vector <Book> choice;


ins.open("bookDB.txt"); //opens book file
if (ins.fail()){
    cout << "file does not exist" << endl; //check for failure
    exit(0);
}

while (!ins.eof()){ //while instream doesn't reach end of file
    
    while(getline(ins, option)) //while reaching eof getline of book of the first argument
    {
        choice.push_back(option); //get the book and push it to the front of the vector
    }
    ins.close(); //close file
}

if (argc == 2)
{
     noneOption (find, choice);
}
if (argc == 3) //if argument counter equals 3
{
    if (arg == "-a") //if argument equals -a
    {
        authorSearch (find, choice); //search using argv 2 and vector choice
    }

    else if (arg == "-t") //if argument equals -t 
    {
        titleSearch (find, choice); //title search
    }

    else if (arg == "-y") //if argument equals -y 
    {
        yearSearch (find, choice); //yearsearch
    }

    else if (arg == "-n") //if argument equals -n
    {
        bookAdd (find, choice, out); //bookAdd
    }

    else if (arg == "-d") //if argument equals -d
    {
        bookDelete(find, choice, out, ins); //book delete
    }
    else {
        cout << "Invalid option was entered" << endl;
        exit(0);
    }
    
    
} 




return 0;

}

void authorSearch (string find, vector <Book> &choice){
    sortYear(choice); //sort by year
    for (size_t i = 0; i < choice.size(); i++) //while i less than size of vector increment
    {
        if(choice[i].matchAuthor(find)) //if vector at i matches author function as argument 2
        {
           cout << choice[i].getTitle() << "|" << choice[i].getYear() << "|" << choice[i].getAuthor() << endl; //cout vector at i (retrieve title), (retrieve author), (retrieve year)
        }
    }
}

void titleSearch (string find, vector <Book> &choice){
    sortYear(choice); //sort by year
    for (size_t i = 0; i < choice.size(); i++) //while i less than size of vector increment
    {
        if(choice[i].matchTitle(find))
        {
            cout << choice[i].getTitle() << "|" << choice[i].getYear() << "|" << choice[i].getAuthor() << endl;
        }
    }
}

void yearSearch (string find, vector <Book> &choice){
    sortYear(choice);
    for (size_t i = 0; i < choice.size(); i++) //while i less than size of vector increment
    {
        if(choice[i].matchYear(find))
        {
            cout << choice[i].getTitle() << "|" << choice[i].getYear() << "|" << choice[i].getAuthor() << endl;
        }
    }
}

void bookAdd (string find, vector <Book> &choice, ofstream &out){ 
    out.open("bookDB.txt"); 
    if (out.fail())
    {
    cout << "Error opening file" << endl;
    exit(0);
    }
    for (size_t i=0; i < choice.size(); i++) //while i is less than size of vector increment
    {
        out << choice.at(i).toString() << endl; //outstream vector at i as using toString function
    }
    choice.push_back(find); //push back string
    out << find;
    cout << "Book has been added!" << endl;
}

void bookDelete (string find, vector <Book> &choice, ofstream &out, ifstream &ins){
    ins.close();
    out.open("bookDB.txt");
    if(out.fail())
    {
        cout << "Error opening file" << endl;
        exit(0);
    }
    for (size_t i = 0; i < choice.size(); i++) //while i less than size of vector increment
    {
        if(choice[i].matchTitle(find)==true)
        {
           choice.erase(choice.begin() + i);
        }

       out << choice[i].toString() << endl;
       
    }
    
}

void noneOption (string find, vector <Book> &choice){
    sortYear(choice);
    for (size_t i = 0; i < choice.size(); i++) //while i less than size of vector increment
    {
        if (choice[i].match(find))
        {
            cout << choice[i].getTitle() << "|" << choice[i].getYear() << "|" << choice[i].getAuthor() << endl;
        }
    }
}

int indexOfsmallest(vector <Book> &choice, int startIndex, size_t endIndex){
int min = choice[startIndex].getYear();
int minIndex = startIndex;
for (size_t i = startIndex; i < endIndex; i++)
{
    if (choice[i].getYear() < min) //if vector at i of getYear is less than min
    {
        min = choice[i].getYear();
        minIndex = i;
    }
}
return minIndex;
}

void sortYear(vector <Book> &choice){
int minIndex;
for (size_t i = 0; i < choice.size()-1; i++) //while i less than size of vector increment
{
    minIndex = indexOfsmallest(choice, i, choice.size());
    swap(choice[i], choice[minIndex]);
}
}

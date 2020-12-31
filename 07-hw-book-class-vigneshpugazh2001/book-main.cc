/**
 *   @file: book-main.cc
 * @author: Vignesh Pugazhenthi
 *   @date: 11/19/2020
 *  @brief: book-main.cc contains only the main program of the book class code
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "book.h"
using namespace std;



int main(int argc, char const *argv[]) {
Book b; //create the object
cout << b.toString() << endl; //couts default constructor

Book b2 = {"The Hitchhiker's Guide to the Galaxy", 1979, "Douglas Adams"}; //example
cout << b2.toString() << endl; //couts example

Book b3 = {"Hello", 2020, "Vignesh"};
b3.output();


}


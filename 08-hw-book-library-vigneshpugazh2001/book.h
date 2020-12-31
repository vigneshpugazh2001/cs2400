/**
 *   @file: book.h
 * @author: Vignesh Pugazhenthi
 *   @date: 12/3/2020
 *  @brief: this file is the header file and contains just the class Book declarations
 */
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;
class Book{
public:
   //constructors (don't have a return type and is the same name as the class)

   /**
 * Book()
 * default values
 * 
 * @param none
 * @return default values
 */ 
   Book (); //default constructor	

   /**
 * Book()
 * second constructor includes newTitle, newYear and newAuthor
 * 
 * @param newTitle, newYear, newAuthor
 * @return none
 */ 
   Book (string newTitle, int newYear, string newAuthor); //second constructor

   /**
 * Book()
 * splits the string specified (allData) into three book properties " |  | "
 * 
 * @param allData
 * @return none
 */ 
   Book (string allData); //splits the string specified (allData) into three book properties " |  | "


  //setters (mutators)

   /**
 * setTitle
 * sets the value for the title
 * 
 * @param newTitle
 * @return none
 */ 
  void setTitle (string newTitle);

  /**
 * setYear
 * sets the value for the year
 * 
 * @param newYear
 * @return none
 */ 
  void setYear (int newYear);

  /**
 * setAuthor
 * sets the value for the author
 * 
 * @param newAuthor
 * @return none
 */ 
  void setAuthor (string newAuthor);

  //getters (accessors)

  /**
 * getTitle
 * returns the value of title
 * 
 * @param 
 * @return title
 */ 
  string getTitle();

  /**
 * getYear
 * returns the value of the year
 * 
 * @param 
 * @return year
 */ 
  int getYear();

  /**
 * getAuthor
 * returns the value of the author
 * 
 * @param 
 * @return author
 */ 
  string getAuthor();

  //helper functions (makes class/design standout)

  /**
 * toString
 * converts year into a string
 * 
 * @param 
 * @return title, year, author
 */ 
  string toString ();
  /**
 * output
 * prints the output
 * 
 * @param 
 * @return title, year, author
 */ 
  void output(); //prints output

  /**
 * matchTitle
 * checks to see if title is true or false
 * 
 * @param targetTitle
 * @return true or false
 */ 
  bool matchTitle (string targetTitle);

  /**
 * matchYear
 * checks to see if year is true or false
 * 
 * @param targetYear
 * @return true or false
 */ 
  bool matchYear (string targetYear);

  /**
 * matchAuthor
 * checks to see if author is true or false
 * 
 * @param targetAuthor
 * @return true or false
 */ 
  bool matchAuthor (string targetAuthor);

  /**
 * match
 * checks to see if matchTitle, matchYear, and matchAuthor is true or false
 * 
 * @param target
 * @return true or false
 */ 
  bool match (string target);

 /**
 * operator
 * checks and compares b and b2 to see if they're true
 * 
 * @param b, b2
 * @return true or false
 */ 
  friend bool operator ==(const Book &b, const Book &b2);
 

private:
string title;
int year;
string author;

};

#endif
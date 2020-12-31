/**
 *   @file: book.cc
 * @author: Vignesh Pugazhenthi
 *   @date: 12/3/2020
 *  @brief: contains all function code based off of class book
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include "book.h"
using namespace std;

void Book::setTitle (string newTitle){ //title setter
  if (newTitle != ""){ //if newTitle does not equal empty string
    title = newTitle; 
  } else {
    title = "***"; //default value
  }
}

string Book::getTitle(){ //getter title
  return title;
}

void Book::setYear (int newYear){ //year setter
  if (newYear >= 0){ //if new year greater than 0
    year = newYear;
  } else {
    year = year; //default value
  }
}

int Book::getYear(){ //year getter
  return year;
}

void Book::setAuthor (string newAuthor){ //author setter
  if (newAuthor != ""){ //if newAuthor does not equal empty string
    author = newAuthor;
  } else {
    author = "***"; //default value
  }
}

string Book::getAuthor (){ //author getter
  return author;
}

Book:: Book(){ //default constructor
title = "***";
year = 0;
author = "***";

}

Book::Book (string newTitle,int newYear, string newAuthor){ //we've set this to default values
	if (newYear >= 0){
		year = newYear;
	} else {
		year = 0; //default value
	}

	if (newTitle != ""){
		title = newTitle;
	} else {
		title = "***"; //default values
	}

	if (newAuthor != ""){
		author = newAuthor;
	} else {
		author = "***";
	}
}

string Book::toString (){
return title + "|" + to_string(year) + "|" + author; //returns year as a string rather than an int
}

void Book:: output (){ //output function
cout << "Title: " << title << endl;
cout << "Year: " << year << endl;
cout << "Author: " << author << endl;

}


bool Book:: matchTitle (string targetTitle){ //matchTitle function
  for (int i = 0; i < title.length(); i++){ //while i is less than title length increment
      if (isupper(title[i])) //if title is uppercase
      {
          title[i] = tolower(title[i]); //title equals lowercase
      }
  }
  for (int i = 0; i < title.length(); i++){ //while i is less than title length increment
      if (isupper(targetTitle[i])) //if tatgetTitle is uppercase
      {
          targetTitle[i] = tolower(targetTitle[i]); //targetTitle is now lowercase
      }
  }
    if (title.find(targetTitle) != string::npos) //if title.find targetTitle does not equal empty string
    {
        return true;
    } 
    else
     {
        return false;
    }

}

bool Book:: matchYear (string targetYear){
  if (to_string(year).find(targetYear) == string::npos) //npos if you find an empty value
  {
    return false;
  }
  else {
    return true;
  }
}

bool Book:: matchAuthor (string targetAuthor){ //matchAuthor function
for (int i = 0; i < author.length(); i++) //while i is less than author length increment
{
    if (isupper(author[i])) //if author is uppercase
    {
        author[i] = tolower(author[i]); //author is now lowercase
    }
}

for (int i = 0; i < author.length(); i++) //if i is less than author length increment
{
    if (isupper(targetAuthor[i])) //if targetAuthor is uppercase
    {
        targetAuthor[i] = tolower(targetAuthor[i]); //targetAuthor is lowercase
    }
}

if (author.find(targetAuthor) == string::npos) //if author.find is targetAuthor is empty string
{
  return false;
}
else {
  return true;
}
}

bool Book::match (string target){ //match
if (matchTitle(target) == true){ //if matchTitle(target) is true
    return true;
}
if (matchYear(target) == true){ //if matchYear(target) is true
    return true;
}
if (matchAuthor(target) == true){ //if matchAuthor(target) is true
    return true;
}
else {
    return false;
}
}

Book::Book (string allData){
  string bar;
  int firstBar = allData.find("|"); //finds until first bar
  title = allData.substr(0, firstBar); //grabs title 
  int secondBar = allData.find("|", firstBar+1); //finds until second bar
  bar = allData.substr(firstBar + 1, secondBar);
  year = atoi(bar.c_str()); //grabs year
  if (year < 0){
      year = 0;
  }
  author = allData.substr(secondBar + 1); //grabs author
}

 bool operator ==(const Book &b, const Book &b2){
  if (b.title == b2.title && b.year == b2.year && b.author == b2.author)
  {
    return true;
  }
  return false;
}






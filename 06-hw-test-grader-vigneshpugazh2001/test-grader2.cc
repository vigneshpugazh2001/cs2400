/**
 *   @file: test-grader.cc
 * @author: Vignesh Pugazhenthi
 *   @date: 11/2/2020
 *  @brief: This program allows the user to print students answer keys from a data file, it then outputs a report of each students performance 
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
/**
 * studentRecord
 * displays each students record of student's first name, last name, their answers, correct answers and the grade they recieved
 * 
 * @param out, firstName, lastName, studentAnswers, answers, gradePercent
 * @return output onto an outstream
 */ 
void studentRecord(ofstream &out, string firstName, string lastName, string studentAnswers, string answers, double gradePercent);
/**
 * getScore
 * compares students answers and correct answers in a for loop then by displaying the students percent
 * 
 * @param out, answers, studentAnswers
 * @return output onto an outstream
 */ 
double getScore(ofstream &out, string answers, string studentAnswers);
/**
 * getGrade
 * converts percentage into a letter grade
 * 
 * @param gradePercent
 * @return output onto an outstream
 */ 
char getGrade(double gradePercent);
int main(int argc, char **argv){

    if (argc != 3) //if argument doesnt equal 3 then
    {
        cout << "./a.out tests.txt tests1.txt" << endl;
        return -1;
    }
    ifstream in;
    in.open(argv[1]); //opening the test.txt is the 1st argument
    if (in.fail())
    {
        cout << "Unable to open file" << endl;
        return -1;
    }
    ofstream out;
    out.open(argv[2]); //outstream open is the 2nd argument
    string answers;
    out << setprecision(1) << fixed; //sets score to one decimal
    in >> answers; //instreams the correct answers
    string firstName;
    string lastName;
    string studentAnswers;
    int n = 0;
    double classAverage = 0.0;
    double gradePercent = 0.0;

    while (!in.eof())
    {
        in >> firstName >> lastName; //instreams first and last name
        getline(in, studentAnswers); //gets instream of students answers
        gradePercent = getScore(out, answers, studentAnswers); //calculates students score
        studentRecord(out, firstName, lastName, studentAnswers, answers, gradePercent); //prints out students answers
        classAverage += gradePercent; //class average is added from each students score
        n++;
    }
    n = n - 1;
    classAverage = classAverage / n; //calculates average
    out << "Class average: " << classAverage << "% " << getGrade(classAverage) << endl;
    out << endl;
    out.close();
    in.close();
    return 0;
}

void studentRecord(ofstream &out, string firstName, string lastName, string studentAnswers, string answers, double gradePercent)
{
    out << lastName << ", " << firstName << endl; //outstreams last name, first name
    out << "--------------------------------------------------------------------------------------------" << endl;
    out << "Answers, correct answer in paranthesis" << endl
        << endl;
    for (int i = 1; i <= answers.size(); i++)
    {
        out << setw(2) << i << ": " << (studentAnswers[i] != ' ' ? studentAnswers[i] : '-') << "(" << answers[i - 1] << ")\t"; //prints student answers and correct answers in parenthesis
        if (i % 5 == 0)
        {
            out << endl;
        }
    }
    out << "\nScore: " << gradePercent << "% " << getGrade(gradePercent) << endl; //outstreams percentage 
    out << "-----------------------------------------------------------------------------------------------" << endl;
}

double getScore(ofstream &out, string answers, string studentAnswers)
{
    int correct = 0;
    double gradePercent = 0.0;
    for (int i = 1; i <= answers.size(); i++)
    {
        answers[i - 1] = tolower(answers[i - 1]); //converts correct answers to lowercase
        studentAnswers[i] = tolower(studentAnswers[i]); //converts student answers to lowercase
        if (answers[i - 1] == studentAnswers[i]) //if answers equal student answers increment
            correct++;
    }
     gradePercent = ((double)correct / answers.size()) * 100; //get grade percentage
    
    return gradePercent;
}
char getGrade(double gradePercent)
{
    if (gradePercent <= 100 && gradePercent >= 90)
        return 'A';
    else if (gradePercent >= 80 && gradePercent <=89)
        return 'B';
    else if (gradePercent >= 70 && gradePercent <=79)
        return 'C';
    else if (gradePercent >= 60 && gradePercent <=69)
        return 'D';
    else
        return 'F';
}

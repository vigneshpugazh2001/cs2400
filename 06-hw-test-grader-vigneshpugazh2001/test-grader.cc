/**
 *   @file: test-grader.cc
 * @author: Enter your name
 *   @date: Enter the date
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
void printReport(ifstream &ins, ofstream &outs);
///function prototypes

int main(int argc, char const *argv[])
{

	string correct;
	string nameFirst;
	string nameLast;
	string answerStudent;
	ifstream file;
	ofstream out;
	if (argc != 3)
	{
		cout << "Please enter: ./a.exe tests.txt tests1.txt" << endl;
	//	exit(0); 
	}
	printReport(file, out);

	file.close();
	return 0;
}

void printReport(ifstream &ins, ofstream &outs)
{
	ins.open("tests.txt");

	outs.open("tests1.txt"); //opens outstream

	string answers;
	string firstName;
	string lastName;
	string s_answers;
	int num = 0;

	while (!ins.eof())
	{
		ins >> firstName;
		ins >> lastName;
		getline(ins, s_answers);
		outs << firstName << ", " << lastName << endl;
		outs << "---------------------------------------------------------------------------" << endl;
		outs << "Answers, correct answer in paranthesis" << endl
			 << endl;
		  int correct = 0;
        double pct = 0.0;

        for (int i = 1; i <= 15; i++)
        {
            
            answers[i - 1] = tolower(answers[i - 1]);
            s_answers[i] = tolower(s_answers[i]);
            // outs << setw(2) << i << ": " << (s_answers[i] != ' ' ? s_answers[i] : '-') << "(" << answers[i - 1] << ")";
			outs << setw(2) << i << ": " << (s_answers[i] != ' ' ? s_answers[i] : '-') << "(" << answers[i] << ")";
			if (answers[i - 1] == answers[i])
                correct++;
            if (i % 5 == 0)
            {
                outs << endl;
            }
        }
		
	}
	
}
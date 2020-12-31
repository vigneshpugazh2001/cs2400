#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;
char getGrade(double perc);
int main(int argc, char **argv)
{
   if(argc!=3) //if argument doesnt equal 3 then
   {
       cout<<"./a.out quiz1.txt output_file.txt"<<endl;
       return -1;
   }
   ifstream in;
   in.open(argv[1]);
   if(in.fail())
   {
       cout<<"Unable to open file"<<endl;
       return -1;
   }
   ofstream out;
   out.open(argv[2]); //outstream open is the 2nd argument
   string answers;
   in>>answers; //instream answers (first line)
   string fname, lname, s_answers;
   out<<setprecision(1)<<fixed; //outstream setprecision(1), fixed
   double class_avg = 0.0;
   int n = 0;
   while(!in.eof())
   {
       in>>fname>>lname; //instreams first and last name
       getline(in, s_answers); //gets instream of students answers
       out<<lname<<", "<<fname<<endl; //outstreams last name, first name 
       out<<"---------------------------------------------------------------------------"<<endl;
       out<<"Answers, correct answer in paranthesis"<<endl<<endl;
       int correct = 0;
       for(int i=1; i<=answers.size(); i++)
       {
           answers[i-1] = tolower(answers[i-1]); //converts correct answers to lowercase
           s_answers[i] = tolower(s_answers[i]); //converts student answers to lowercase
           out<<setw(2)<<i<<": "<<(s_answers[i]!=' '?s_answers[i]:'-')<<"("<<answers[i-1]<<")\t"; //outstream: question number, studentanswer(correctanswer)
           if(answers[i-1]==s_answers[i])
               correct++;
           if(i%5==0)
               out<<endl;
       }
       double perc = ((double)correct/answers.size())*100; //get grade percentage
       class_avg += perc; //class avg declared line 28
       n++;
       out<<"\nScore: "<<perc<<"% "<<getGrade(perc)<<endl;
       out<<"---------------------------------------------------------------------------"<<endl;
       class_avg /= n;
       out<<"Class average: "<<class_avg<<" "<<getGrade(class_avg)<<endl;
       out<<endl;
   }
   out.close();
   in.close();
   return 0;
}
char getGrade(double perc)
{
   if(perc>=90)
       return 'A';
   else if(perc>=80)
       return 'B';
   else if(perc>=70)
       return 'C';
   else if(perc>=60)
       return 'D';
   else
       return 'F';
}
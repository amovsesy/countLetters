/* Aleksandr Movsesyan
     Programming Lab 5
     pl5.cpp
     CS 110A
     Craig Persiko

    This program uses file input to count a number of letters and words in a
program and outputs the results and the average letters per
    word
  */

#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

void magic_formula ();
// makes the output to a percision of 2

int main()
{

  int letters = 0, words = 0;
  double average;
  char inputFileName[51], c, last_c;

  ifstream fin;

  cout << "Welcome to the Word Count and Average Length Program!\n\n";
  cout << "Please enter the name of a file to input (50 chars max in
filename):\n";
  cin >> inputFileName;

  fin.open ( inputFileName );
  if ( fin.fail () )
  {
    cout << "\nError opening " << inputFileName << endl;
    return 0;
  }

  fin.get (c);
  while ( !fin.eof () )
  {
    if ( !isspace (c) && c != ',' && c != '.' )
    {
      letters++;
    }
    else
    {
      if ( !isspace (last_c) && last_c != ',' && last_c != '.' )
      {
        words++;
      }
    }
    last_c = c;
    fin.get (c);
  }

  average =  static_cast<double>(letters) / words;

  magic_formula ();

  cout << "Number of words in file is: " << words << endl << "Average word
length is: "
       << average << " leters"  << endl << endl;

  fin.close ();

  return 0;
}

// makes the output to a percision of 2
void magic_formula ()
{

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

}

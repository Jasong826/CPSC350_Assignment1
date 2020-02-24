#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

int main(int argc, char** argv)
{
  //initializing variables for calculations and fileIO
  ifstream myFile ("dna.txt");
  int strSize = 0;
  int sum = 0;
  int count = 0;
  int mean = 0;
  int var = 0;
  int stDev = 0;

  //checks if file is opened
  if (!myFile)
  {
    cout << "Error: couldn't open file!";
  }

//reads the file
while (myFile)
{
  string line;

  getline(myFile, line);
  cout << "reading line" << endl;
  strSize = line.size();


  //stop when reached end of the file
  if (strSize == 0)
  {
    cout << "Stopped reading because encountered a line with zero characters!" << endl;
  break;
  }
  count = count + 1;

  //adding up sum of length of strings
  sum = strSize + sum;

  //printing out results
  cout << line << endl;
  cout << "Size of the string is: " << strSize << endl;

  cout << "Sum: " << sum << endl;
  mean = sum/count;
  cout << "Mean: " << mean << endl;
  int diff = abs(strSize - mean);
  var = var + pow(diff,2);
  cout << "incomplete var: " << var << endl;
}
var = var / (count-1);
cout << "Variance: " << var << endl;
stDev = sqrt(var);
cout << "Standard Deviation: "<< stDev << endl;

myFile.close();

  return 0;


}

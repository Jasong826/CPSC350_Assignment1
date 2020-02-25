#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
  //initializing variables for calculations and fileIO
  ifstream dnaFile ("dna.txt");
  ofstream outputFile ("jasonsong.txt");
  string fileName = argv[1];
  int strSize = 0;
  int sum = 0;
  int lineCount = 0;
  int mean = 0;
  int var = 0;
  int stDev = 0;
  string varList = "";
  int charCount = 0;
  //initializing single nucleotide counts
  float A_Count = 0.0;
  float C_Count = 0.0;
  float G_Count = 0.0;
  float T_Count = 0.0;
  //initializing bigrams
  float AA_Count = 0.0;
  float AC_Count = 0.0;
  float AG_Count = 0.0;
  float AT_Count = 0.0;
  float CA_Count = 0.0;
  float CC_Count = 0.0;
  float CG_Count = 0.0;
  float CT_Count = 0.0;
  float GA_Count = 0.0;
  float GC_Count = 0.0;
  float GG_Count = 0.0;
  float GT_Count = 0.0;
  float TA_Count = 0.0;
  float TC_Count = 0.0;
  float TG_Count = 0.0;
  float TT_Count = 0.0;
  //initializing probabilities of nucleotides
  float A_prob = 0.0;
  float C_prob = 0.0;
  float G_prob = 0.0;
  float T_prob = 0.0;
  //initializing probabilities of bigrams
  float AA_prob = 0.0;
  float AC_prob = 0.0;
  float AG_prob = 0.0;
  float AT_prob = 0.0;
  float CA_prob = 0.0;
  float CC_prob = 0.0;
  float CG_prob = 0.0;
  float CT_prob = 0.0;
  float GA_prob = 0.0;
  float GC_prob = 0.0;
  float GG_prob = 0.0;
  float GT_prob = 0.0;
  float TA_prob = 0.0;
  float TC_prob = 0.0;
  float TG_prob = 0.0;
  float TT_prob = 0.0;


  //checks if there in an input for fileName
  /*
  if (argc>0)
  {
    cout << "opening and reading: " << fileName << endl;
    ifstream dnaFile (fileName);
    dnaFile.open(fileName);
  }
  else
  {
    cout << "No argument provided in the command line! Please try again!" << endl;
  }

  //checks if file is opened
  if (!dnaFile)
  {
    cout << "Invalid file!" << endl;
  }
*/
  //reads the file
  while (dnaFile)
  {
    string line;
    getline(dnaFile, line);

    //get size of the string
    strSize = line.size();
    cout << "reading line" << endl;

    //go through the line to count for nucleotides and bigrams


    //iterates through each character in the line to count how many times each nucleotide appears
    for(int i = 0; i < strSize; ++i)  {
      charCount ++;
      if (line[i] == 'A' || line[i] == 'a')
      {
        A_Count ++;
        if (line[i+1] == 'A' || line[i+1] == 'a')
          AA_Count ++;
        if (line[i+1] == 'C' || line[i+1] == 'C')
          AC_Count ++;
        if (line[i+1] == 'G' || line[i+1] == 'g')
          AG_Count ++;
        if (line[i+1] == 'T' || line[i+1] == 't')
          AT_Count ++;
      }
      if (line[i] == 'C' || line[i] == 'c')
      {
        C_Count ++;
        if (line[i+1] == 'A' || line[i+1] == 'a')
          CA_Count ++;
        if (line[i+1] == 'C' || line[i+1] == 'C')
          CC_Count ++;
        if (line[i+1] == 'G' || line[i+1] == 'g')
          CG_Count ++;
        if (line[i+1] == 'T' || line[i+1] == 't')
          CT_Count ++;
      }
      if (line[i] == 'G' || line[i] == 'g')
      {
        G_Count ++;
        if (line[i+1] == 'A' || line[i+1] == 'a')
          GA_Count ++;
        if (line[i+1] == 'C' || line[i+1] == 'C')
          GC_Count ++;
        if (line[i+1] == 'G' || line[i+1] == 'g')
          GG_Count ++;
        if (line[i+1] == 'T' || line[i+1] == 't')
          GT_Count ++;
      }
      if (line[i] == 'T' || line[i] == 't')
      {
        T_Count ++;
        if (line[i+1] == 'A' || line[i+1] == 'a')
          TA_Count ++;
        if (line[i+1] == 'C' || line[i+1] == 'C')
          TC_Count ++;
        if (line[i+1] == 'G' || line[i+1] == 'g')
          TG_Count ++;
        if (line[i+1] == 'T' || line[i+1] == 't')
          TT_Count ++;
      }
    }


    //stop when reached end of the file
    if (strSize == 0)
    {
      cout << "Stopped reading because encountered a line with zero characters!" << endl;
    break;
    }

    //increment the count of lines in the file
    lineCount ++;
    //adding up number of length of strings
    sum = strSize + sum;

    //printing out results
    cout << "line: " << line << endl;
    cout << "Size: " << strSize << endl;
    cout << "Number of A: " << A_Count << endl;
    cout << "Number of C: " << C_Count << endl;
    cout << "Number of G: " << G_Count << endl;
    cout << "Number of T: " << T_Count << endl;

    /*
    cout << "Sum: " << sum << endl;
    cout << "Mean: " << mean << endl;
    cout << "incomplete var: " << var << endl;
    */


  }
  //calculate mean of the size of strings
  mean = sum/lineCount;

  //calculate variance and standard Deviation
  var =

  //nucleotide probability
  A_prob = (A_Count/charCount)*100;
  C_prob = (C_Count/charCount)*100;
  G_prob = (G_Count/charCount)*100;
  T_prob = (T_Count/charCount)*100;
  //bigram probability
  AA_prob = (AA_Count/charCount)*100;
  AC_prob = (AC_Count/charCount)*100;
  AG_prob = (AG_Count/charCount)*100;
  AT_prob = (AT_Count/charCount)*100;
  CA_prob = (CA_Count/charCount)*100;
  CC_prob = (CC_Count/charCount)*100;
  CG_prob = (CG_Count/charCount)*100;
  CT_prob = (CT_Count/charCount)*100;
  GA_prob = (GA_Count/charCount)*100;
  GC_prob = (GC_Count/charCount)*100;
  GG_prob = (GG_Count/charCount)*100;
  GT_prob = (GT_Count/charCount)*100;
  TA_prob = (TA_Count/charCount)*100;
  TC_prob = (TC_Count/charCount)*100;
  TG_prob = (TG_Count/charCount)*100;
  TT_prob = (TT_Count/charCount)*100;

  //print out final results
  outputFile << "Jason Song" << endl << "ID: 2327590" << endl << "Email: Jasong@chapman.edu" << endl;


  /*
  var = var / (lineCount);
  cout << "Variance: " << var << endl;
  stDev = sqrt(var);
  cout << "Standard Deviation: "<< stDev << endl;
  */

  //print out probabilities to output file
  outputFile << "-----------------------------------------------------------------" << endl;
  outputFile << "Total length of strings: " << sum << endl;
  outputFile << "Mean of the length of strings: " << mean << endl;
  outputFile << "Probability of A: %" << A_prob << endl;
  outputFile << "Probability of C: %" << C_prob << endl;
  outputFile << "Probability of G: %" << G_prob << endl;
  outputFile << "Probability of T: %" << T_prob << endl;
  outputFile << "Probability of AA: %" << AA_prob << endl;
  outputFile << "Probability of AC: %" << AC_prob << endl;
  outputFile << "Probability of AG: %" << AG_prob << endl;
  outputFile << "Probability of AT: %" << AT_prob << endl;
  outputFile << "Probability of CA: %" << CA_prob << endl;
  outputFile << "Probability of CC: %" << CC_prob << endl;
  outputFile << "Probability of CG: %" << CG_prob << endl;
  outputFile << "Probability of CT: %" << CT_prob << endl;
  outputFile << "Probability of GA: %" << GA_prob << endl;
  outputFile << "Probability of GC: %" << GC_prob << endl;
  outputFile << "Probability of GG: %" << GG_prob << endl;
  outputFile << "Probability of GT: %" << GT_prob << endl;
  outputFile << "Probability of TA: %" << TA_prob << endl;
  outputFile << "Probability of TC: %" << TC_prob << endl;
  outputFile << "Probability of TG: %" << TG_prob << endl;
  outputFile << "Probability of TT: %" << TT_prob << endl;



  outputFile.close();
  dnaFile.close();

  return 0;


}

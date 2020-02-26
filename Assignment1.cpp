#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
  //initializing variables for calculations and fileIO
  ifstream dnaFile;
  string fileName = argv[1];
  int strSize = 0;
  int sum = 0;
  int lineCount = 0;
  int mean = 0;
  int var = 0;
  int stDev = 0;
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


while(true){

  //checks if there in an input for fileName
  if (argc>0)
  {
    cout << "opening and reading: " << fileName << endl;
    dnaFile.open(fileName);
  }
  else
  {
    cout << "No argument provided in the command line! Please try again!" << endl;
    exit(1);
  }

  //reads the dna strings in the file
  while (true)
  {
    string line  = "";
    getline(dnaFile, line);
    //get size of the string
    strSize = line.size();
    //cout << "reading line" << endl;
    //go through the line to count for nucleotides and bigrams
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
      //cout << "Stopped reading file because encountered a line with zero characters!" << endl;
      break;
    }
    //increment the count of lines in the file
    lineCount ++;
    //adding up number of length of strings
    sum = strSize + sum;
    //printing out results
    /*
    cout << "line: " << line << endl;
    cout << "Size: " << strSize << endl;
    cout << "Number of A: " << A_Count << endl;
    cout << "Number of C: " << C_Count << endl;
    cout << "Number of G: " << G_Count << endl;
    cout << "Number of T: " << T_Count << endl;
    */
    //end of while loop
  }

  dnaFile.close();
  //calculate mean of the size of strings
  mean = sum/lineCount;
  //reopen file to calc variance
  dnaFile.open(fileName);
  int total = 0;
  //calculate variance and standard Deviation
  for(int i = 0; i < lineCount; ++i)
  {
    //cout << "for Var: " << endl;
    string line1 = "";
    getline(dnaFile, line1);
    int size = line1.size();
    //cout << "String: " << line1 << endl;
    //cout << "String size: " << size << endl;
    var = abs(mean-size);
    //cout << var << endl;
    var = pow(var, 2);
    //cout << var << endl;
    total = total + var;
    //cout << total << endl;
  }
  var = total/lineCount;
  stDev = sqrt(var);

  //nucleotide probability
  A_prob = (A_Count/(charCount-lineCount))*100;
  C_prob = (C_Count/(charCount-lineCount))*100;
  G_prob = (G_Count/(charCount-lineCount))*100;
  T_prob = (T_Count/(charCount-lineCount))*100;
  //bigram probability
  AA_prob = (AA_Count/(charCount-lineCount))*100;
  AC_prob = (AC_Count/(charCount-lineCount))*100;
  AG_prob = (AG_Count/(charCount-lineCount))*100;
  AT_prob = (AT_Count/(charCount-lineCount))*100;
  CA_prob = (CA_Count/(charCount-lineCount))*100;
  CC_prob = (CC_Count/(charCount-lineCount))*100;
  CG_prob = (CG_Count/(charCount-lineCount))*100;
  CT_prob = (CT_Count/(charCount-lineCount))*100;
  GA_prob = (GA_Count/(charCount-lineCount))*100;
  GC_prob = (GC_Count/(charCount-lineCount))*100;
  GG_prob = (GG_Count/(charCount-lineCount))*100;
  GT_prob = (GT_Count/(charCount-lineCount))*100;
  TA_prob = (TA_Count/(charCount-lineCount))*100;
  TC_prob = (TC_Count/(charCount-lineCount))*100;
  TG_prob = (TG_Count/(charCount-lineCount))*100;
  TT_prob = (TT_Count/(charCount-lineCount))*100;

  //print out final results
  ofstream outputFile ("jasonsong.txt");
  outputFile << "Jason Song" << endl << "ID: 2327590" << endl << "Email: Jasong@chapman.edu" << endl;
  outputFile << endl << "-----------------------------------------------------------------" << endl << endl;
  outputFile << "Total length of strings: " << sum << endl;
  outputFile << "Mean of the length of strings: " << mean << endl;
  outputFile << "Variance: " << var << endl;
  outputFile << "Standard Deviation: " << stDev << endl;
  outputFile << endl << "Probabilities of nucleotides" << endl;
  outputFile << "Probability of A: %" << A_prob << endl;
  outputFile << "Probability of C: %" << C_prob << endl;
  outputFile << "Probability of G: %" << G_prob << endl;
  outputFile << "Probability of T: %" << T_prob << endl;
  outputFile << endl << "Probability of bigrams" << endl;
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

  for(int k = 0; k < 1000; ++k)
  {
    //initialize to use formulas that were provided in the pdf file
    double a;
    double b;
    double c;
    double d;

    string dnaStrand = "";

    //generate random number from 0 - 32767
    a = rand() % RAND_MAX;
    b = rand() % RAND_MAX;
    //divide the random number by 32767 to get a number in between 0 and 1
    a = a / RAND_MAX;
    b = b / RAND_MAX;
    //calculate for random lengths of dna strings
    c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
    d = stDev * c + mean;
    //cout << a << " " << b << " " << c << " " << d << endl;
    //print out random strings of dna of length d
    for(int l = 0; l < d; ++l)
    {
      double randNuc = rand() % RAND_MAX;
      randNuc = randNuc / RAND_MAX * 100;
      if(randNuc <= A_prob)
        dnaStrand += "A";
      else if(randNuc <= (A_prob + C_prob))
        dnaStrand += "C";
      else if(randNuc <= (A_prob + C_prob + G_prob))
        dnaStrand += "G";
      else if(randNuc <= (A_prob + C_prob + G_prob + T_prob))
        dnaStrand += "T";
    }
    outputFile << dnaStrand;
    outputFile <<endl;
  }

  outputFile.close();

  //ask the user to try again
  char userAns;
  cout << "If you would like to read from another file please enter 'y' for yes or 'n' to exit this program: " << endl;
  cin >> userAns;
  if (userAns == 'y'){
    cout << "Please enter in your file name: ";
    cin >> fileName;
  }
  else if (userAns == 'n'){
    exit(1);
  }
  else {
    cout << "Invalid input!" << endl;
    exit(1);
  }
}

  dnaFile.close();


  return 0;


}

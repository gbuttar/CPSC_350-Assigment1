#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
  //To check user input of the DNA String file
  string commandLineFile;
    if (argc != 2){ //checks to make sure user inputted a file
      cout<<"Please enter a DNA String File name into the command line!"<<endl;
      exit(1); //restart the program to have user
    }
    else{
      commandLineFile= argv[1]; //the user input of the .txt file //commandLineFile now stores the inputted file name
    }
  ifstream inputFile; //commandLine file turns into inputFile
    inputFile.open(commandLineFile,ios::in); // opens the inputted CommandLineFile
    if(inputFile.is_open()){
      cout<<"File was succesfully opened!"<<endl;
    }
    else{
      cout<<"Error: file did not open. Please try again."<<endl;
      exit(1);
    }
    string tempLine;
    string dnaString = "";
    //variables for summary statistics
    float sum = 0.0;
    float mean = 0.0;
    float variance = 0.0;
    float stDev = 0.0;
    float itemCount = 0.0;

    //making file a string to access
    while(!inputFile.eof()){ //
      inputFile >> tempLine;
      dnaString.append(tempLine + " ");
      sum += tempLine.length();
      itemCount++; //keeps track of how many times the while loop went through to give the number of items in the .txt file
    }
    mean = sum/itemCount;

    //variables for variance
    float dnaLengthCount = 0.0;
    float topFraction = 0.0;
    string makeString;
    float topFractionSum =0.0;

    //function to find the variance
    for(int i = 0; i< dnaString.length(); ++i){ //for each character//dnastringlen = 36
    makeString = dnaString[i];
      if(makeString == " "){
       topFraction = (dnaLengthCount - mean);
       topFraction = pow(topFraction, 2);
       topFractionSum += topFraction;
       dnaLengthCount = 0.0;
      }
      else{
        dnaLengthCount++; //if it does not go into the statement then the letter is counted
    }
  }

  variance = topFractionSum/itemCount;
  stDev = sqrt(variance);

  //variables for nucleotides to keep count
  float numA = 0.0;
  float numC = 0.0;
  float numG = 0.0;
  float numT = 0.0;
  float totalNumb = 0.0;
  //variables for nucleotide bigrams to keep count
  float numAC = 0.0;
  float numAG = 0.0;
  float numAT = 0.0;
  float numAA = 0.0;
  float numCC = 0.0;
  float numCG = 0.0;
  float numCT = 0.0;
  float numCA= 0.0;
  float numGG = 0.0;
  float numGA = 0.0;
  float numGC = 0.0;
  float numGT = 0.0;
  float numTT = 0.0;
  float numTA = 0.0;
  float numTC = 0.0;
  float numTG = 0.0;
  float totalBigram = 0.0;

  string upperCaseChar = "";
  string upperCaseString = "";

  //check to make sure all the cases of the nucleotides are uppercase
  for(char& dnaUpper: dnaString){
    upperCaseChar = toupper(dnaUpper);
    upperCaseString.append(upperCaseChar);
  }
  //counts how many of each nucleotide
 for(char& dnaCharacter: dnaString){
  char letter = (dnaCharacter);
  switch(letter){
    case 'A':
      numA++;
      totalNumb++;
      break;
    case 'C':
      numC++;
      totalNumb++;
      break;
    case 'G':
      numG++;
      totalNumb++;
      break;
    case 'T':
      numT++;
      totalNumb++;
      break;
    default:
    break;
    }
  }
    //variables for bigram count
    string CaseBigram1 = "";
    string CaseBigram2 = "";
    string bigram = " ";
    string space;

    //function to make bigrams and then count them
  for (int i = 0; i< dnaString.length(); ++i){
    space = dnaString[i]; //stop at space
    if(space != " "){
      CaseBigram1 = (dnaString[i]);
      CaseBigram2 = (dnaString[i+1]);
      bigram = CaseBigram1 + CaseBigram2; //creates bigram
    if(bigram == "AA"){ //checks/makes count of total bigrams
      numAA++;
      totalBigram++;
      bigram = " ";
    }
    else if(bigram == "AT"){
      numAT++;
      totalBigram++;
      bigram = " ";
    }
   else if(bigram == "AC"){
     numAC++;
     totalBigram++;
     bigram = " ";
   }
   else if(bigram == "AG"){
     numAG++;
     totalBigram++;
     bigram = " ";
  }
   else if(bigram == "CC"){
     numCC++;
     totalBigram++;
     bigram = " ";
  }
   else if(bigram == "CG"){
    numCG++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "CA"){
    numCA++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "CT"){
    numCT++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "GG"){
    numGG++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "GA"){
    numGA++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "GC"){
    numGC++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "GT"){
    numGT++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "TT"){
    numTT++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "TA"){
    numTA++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "TG"){
    numTG++;
    totalBigram++;
    bigram = " ";
  }
  else if(bigram == "TC"){
    numTC++;
    totalBigram++;
    bigram = " ";
  }
  i++;
  }
  }

  //calculate the probabilty of each nucleotide
  float probOfA = numA/totalNumb;
  float probOfC = numC/totalNumb;
  float probOfG = numG/totalNumb;
  float probOfT = numT/totalNumb;

  //calculate the probabilty of each nucleotide bigram
  float probOfAA = numAA/totalBigram;
  float probOfAT = numAT/totalBigram;
  float probOfAG = numAG/totalBigram;
  float probOfAC = numAC/totalBigram;
  float probOfCC = numCC/totalBigram;
  float probOfCA = numCA/totalBigram;
  float probOfCG = numCG/totalBigram;
  float probOfCT = numCT/totalBigram;
  float probOfGG = numGG/totalBigram;
  float probOfGC = numGC/totalBigram;
  float probOfGT = numGT/totalBigram;
  float probOfGA = numGA/totalBigram;
  float probOfTT = numTT/totalBigram;
  float probOfTA = numTA/totalBigram;
  float probOfTC = numTC/totalBigram;
  float probOfTG = numTG/totalBigram;

  float pi = 3.14159265359;
  string bigString = "";
  //Guassian distribution to generate 1000 new strings
  for(int i =0; i < 1000; ++i){
    float a = (float)rand() / RAND_MAX;
    float b = (float)rand() / RAND_MAX;
    float C = sqrt(((-2)*(log10(a))) * (cos(2*pi*b)));
    float D = abs((stDev*C)+ mean); //length of the string generated, Gaussian variable
    //generate the nucleotides with the correct length using D and append to the end of myFile
    for(int i = 0; i < D; ++i){ //making a specific string to output new generated strings, with same probability as original
      float randNum = (float)rand() / RAND_MAX;
      if(randNum < probOfA){
        bigString.append("A");
      }
      else if(randNum< probOfC + probOfA){
        bigString.append("C");
      }
      else if(randNum < probOfT + probOfC + probOfA){
        bigString.append("T");
      }
      else if(randNum < probOfG + probOfT + probOfC + probOfA){
        bigString.append("G");
      }
      bigString +=" ";
  }
}
  //output the results into my own named file
  fstream myFile;
  myFile.open("GurleeButtar.txt", ios::out);
  myFile<<"Name: Gurleen Buttar \nStudent ID: 2328033 \nClass: CPSC350-03\n"<< endl;
  myFile<<"The Sum of the length of DNA Strings in the list: " <<sum<<endl;
  myFile<<"The Mean of the length of DNA Strings in the list: "<<mean<<endl;
  myFile<<"The Variance of the length of DNA Strings in the list: "<<variance<<endl;
  myFile<<"The Standard Deviation of the length of the DNA Strings in the list: "<<stDev<< "\n"<<endl;
  myFile<<"The Relative Probability of each nucleotide: "<< "\n"<<endl;
  myFile<<"For nucleotide A: "<<probOfA<<endl;
  myFile<<"For nucleotide C: "<<probOfC<<endl;
  myFile<<"For nucleotide T: "<<probOfT<<endl;
  myFile<<"For nucleotide G: "<<probOfG<< "\n" <<endl;
  myFile<<"The Relative Probability of each nucleotide bigram: "<< endl;
  myFile<<"AA:      "<<probOfAA<<endl;
  myFile<<"AC:      "<<probOfAC<<endl;
  myFile<<"AT:      "<<probOfAT<<endl;
  myFile<<"AG:      "<<probOfAG<<endl;
  myFile<<"CC:      "<<probOfCC<<endl;
  myFile<<"CA:      "<<probOfCA<<endl;
  myFile<<"CT:      "<<probOfCT<<endl;
  myFile<<"CG:      "<<probOfCG<<endl;
  myFile<<"GG:      "<<probOfGG<<endl;
  myFile<<"GA:      "<<probOfGA<<endl;
  myFile<<"GC:      "<<probOfGC<<endl;
  myFile<<"GT:      "<<probOfGT<<endl;
  myFile<<"TT:      "<<probOfTT<<endl;
  myFile<<"TA:      "<<probOfTA<<endl;
  myFile<<"TC:      "<<probOfTC<<endl;
  myFile<<"TG:      "<<probOfTG<<endl;
  myFile<<"\n1000 DNA Strings: \n" <<bigString<<endl;
  //closes the files
    inputFile.close();
    myFile.close();
}

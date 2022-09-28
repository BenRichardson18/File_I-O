/*
Ben Richardson
C++ Fall 2022
Due: September 28th
Lab 3 User and File I/O
Demonstration of inputting files with integers and outputing the solution for the mean and for the population standard deviation on the screen and the file. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

string inputFileName = "inMeanStd.dat";
string outputFileName = "outMeanStd.dat";

float MeanCalc(float data[]);
float stdDevCalc(float data[]);

int main()
{

	// We call in our input file for our integers and to later output the solution in to an output file
	ifstream infile;
	infile.open(inputFileName);

	ofstream outfile;
	outfile.open(outputFileName);

	int num1;
	int num2;
	int num3;
	int num4;

	infile >> num1 >> num2 >> num3 >> num4;
	// We are declaring that our calculations will have a set amount of 4 elements/numbers 
	float val[4] = { num1, num2, num3, num4 };
	float variance = 0, stdDev1, mean1, sum1 = 0;
	int x;
	// We have our mean operation
	for (x = 0; x < 4; ++x)
		sum1 += val[x];
	mean1 = sum1 / 4;
	// We have our population standard deviation operation 
	for (x = 0; x < 4; ++x)
		variance += pow(val[x] - mean1, 2);
	variance = variance / 4;
	stdDev1 = sqrt(variance);
	// We output to the screen the solution for the integers from the input file
	cout << "A mean value given by a set of 4 integers inputted by a file called inMeanStd = " << endl << mean1 << endl;
	cout << endl << "A population standard deviation given by a set of 4 integers that are inputted by a file called inMeanStd = " << endl << stdDev1 << endl;
	
	outfile << num1 << num2 << num3 << num4;
	// We are outputting the solution to the output file 
	infile.close();
	outfile << endl << "The mean is = " << mean1 << endl;
	outfile << "The population standard deviation is = " << stdDev1 << endl;
	outfile.close();
	// We assign new numbers for the user to input  
	int l;
	float data[4];
	// The user inputs the 4 numbers they require
	cout << endl << "Enter 4 numbers: ";
	for (l = 0; l < 4; ++l)
	{
		cin >> data[l];
	}
	// We output to the screen the solution from the mean and the standard deviation operation that we stored as a float so that there is no need to write it again 
	cout << endl << "The mean from the numbers inputted by the user = " << endl << MeanCalc(data) << endl;
	cout << endl << "The population standard deviation from the numbers inputted by the user = " << endl << stdDevCalc(data) << endl;

	return 0;

}

float MeanCalc(float data[])
{
	float sum = 0, mean;
	int l;

	for (l = 0; l < 4; ++l)
	{
		sum += data[l];
	}

	mean = sum / 4;

	return mean;
}

float stdDevCalc(float data[])
{
	float sum = 0.0, mean, stdDev2 = 0.0;
	int l;

	for (l = 0; l < 4; ++l)
	{
		sum += data[l];
	}

	mean = sum / 4;

	for (l = 0; l < 4; ++l)
	{
		stdDev2 += pow(data[l] - mean, 2);
	}

	return sqrt(stdDev2 / 4);

}
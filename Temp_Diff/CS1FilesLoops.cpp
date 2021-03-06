// CS1FilesLoops.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"  <--use if necessary for compiler
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

float Average(float total, float numb_of_temps);
float Difference_Of(float a, float b);
using namespace std;

int main()
{
	float current_temp, total = 0, Average_Of_Total_Temps = 0;
	float numb_of_temps = 0, Difference_Of_Temps = 0, previous_temp = 0;
	ifstream myfile; myfile.open("infile.txt"); 
	
	cout << "Travis Brown\n@02822994\nLab 4\nFeb 8, 2018" << endl <<
		"Problem: Compute the difference between temperatures and the average temperature"
		<< endl;

	cout << "\n\nTEMP\tDIFF\n\n" << endl;
	
	while(!myfile.eof()){ 
		/*The while loops condition will contion to loop until we have reached 
		the end of the file/ read in all the values*/
		
		myfile >> current_temp; //reading in the first value
		
		total += current_temp; 
		
		/*The if statement below prevents printing difference 
		of 2 temperatures when we have only read in a single temperature */
		if (numb_of_temps > 0) {
			Difference_Of_Temps = Difference_Of(current_temp,previous_temp);
			cout << current_temp << "\t" << Difference_Of_Temps << endl;
		}
		else {
			cout << current_temp << endl;
		}
		
		numb_of_temps += 1;	
		previous_temp = current_temp; /* carries over the temp into the next cycle 
		 to calculate the difference*/
	};
	
	Average_Of_Total_Temps = Average(total, numb_of_temps);//averaging the Temperatures

	cout << "\n\nAverage Temperature: " << fixed << setprecision(2) 
		<< Average_Of_Total_Temps << endl; 
	//fixed & setprecison control the number of decimal places in the following number
	
	myfile.close();
    return 0;
}
float Average(float total, float numb_of_temps) {
	return (total / numb_of_temps);
}
float Difference_Of(float a, float b) {
	return a-b; 
}
/*
Travis Brown
@02822994
Lab 4
Feb 8, 2018
Problem: Compute the difference between temperatures and the average temperature


TEMP    DIFF


34.5
38.6    4.1
42.4    3.8
46.8    4.4
51.3    4.5
63.1    11.8
60.2    -2.9
55.9    -4.3
60.3    4.4
56.7    -3.6
50.3    -6.4
42.2    -8.1


Average Temperature: 50.19
Press any key to continue . . .

*/
//#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void heading();
const float reimbursement_rate = 0.35;

int main()
{
	float beginning_odom_reading, ending_odom_reading;
	float difference, reimbursement;
	heading();
		
	cout << "\nMILEAGE REIMBURSEMENT CALCULATOR\n" << endl;
	
	cout << "Enter beginning odometer reading=> ";//prompt user input
	cin >> beginning_odom_reading;//get user input

	cout << "\nEnter ending odometer reading=> ";//prompt user input
	cin >> ending_odom_reading;//get user input
	
	cout << fixed << showpoint;
	difference = ending_odom_reading - beginning_odom_reading;//subtract ending input from beginning input
	reimbursement = difference * 0.35; //multiply difference by 0.35

	cout << setprecision(2) << "\nYou traveled " << difference
		<< " miles.\tAt $0.35 per mile, your reimbursement is $"
		<< reimbursement << endl; // output data

    return 0;
}
void heading() {
	string stars = "********************************************";
	cout << stars << "\nTravis Brown\nID @02822994\nSYCS-135 Computer Science I\n"
		<< "Class Exercise 1\nFebruary 12, 2018\n" << stars << endl;
}
/*
********************************************
Travis Brown
ID @02822994
SYCS-135 Computer Science I
Class Exercise 1
February 12, 2018
********************************************

MILEAGE REIMBURSEMENT CALCULATOR

Enter beginning odometer reading=> 55044

Enter ending odometer reading=> 55178

You traveled 134.00 miles.      At $0.35 per mile, your reimbursement is $46.90
Press any key to continue . . .
*/

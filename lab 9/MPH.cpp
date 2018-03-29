#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

void PrintData(int miles, int hours);
void GetData(int &miles, int &hours);

int main() {
	int miles, hours;
	GetData(miles, hours);//prompts for miles and hours
	PrintData(miles,hours);//shows miles per hour travelled or to be
	return 0;
}
void PrintData(int miles, int hours) {
	cout << "The number of miles is " << miles << endl;
	cout << "The number of hours is " << hours << endl;
	cout << fixed << setprecision(2);
	cout << "The number of miles per hour is " << miles/1.0/hours << endl;
}
void GetData(int &miles, int &hours) {
	cout << "Enter the number of miles: ";cin >> miles;
	cout << "Enter the number of hours: ";cin >> hours;
}
/*
Enter the number of miles: 9876543
Enter the number of hours: 7
The number of miles is 9876543
The number of hours is 7
The number of miles per hour is 1410934.71
*/
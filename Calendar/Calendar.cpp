/*
CODED BY TRAVIS BROWN 
*/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int Get_Year();
int Get_Starting_Day();
void Print_Heading(int year);
string Read_Month_Name();
int Read_Num_Days();
int Print_Month(string month_name, int num_of_days, int start_date);
ifstream myfile;

int main() {
	int year, num_of_days;int start_date;
	string month_name;
	 myfile.open("infile.txt");
	
	year = Get_Year();//ask for the requested year
	start_date = Get_Starting_Day();// ask for the day that the year starts on
	Print_Heading(year);
	do{
		month_name = Read_Month_Name();//collects month
		num_of_days = Read_Num_Days();//collects number of days in the month
		start_date = Print_Month(month_name, num_of_days, start_date);
		//formats month, days of the week and 1 to number of days
	}while (!myfile.eof());// loops while not at the end of the file
	return 0;
}
int Get_Year() {
	int yearEntered;
	cout << "Enter the year:\t"; 
	cin >> yearEntered;
	return yearEntered;
}
int Get_Starting_Day() {
	int start_date;
	cout << "\n(0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat)\n";
	cout << "Enter the start date: ";
	cin >> start_date;
	return start_date;
}
void Print_Heading(int year) {
	cout << setw(29) << " YEAR --- " << year << endl;
}
string Read_Month_Name() {
	string month_name;
	myfile >> month_name;
	return month_name;
}
int Read_Num_Days() {
	int num_of_days;
	myfile >> num_of_days;
	return num_of_days;
}
int Print_Month(string month_name, int num_of_days, int start_date) {
	
	int day = start_date;
	int starting_point = day;
	cout << "\n\n" << setw(29) << month_name << endl;
	cout << "Sun\tMon\tTues\tWed\tThu\tFri\tSat" << endl;
	for (int i = 0; i < starting_point ; i++) {
		cout << "\t";
	}//starts on the designated day
	
	for (int a = 1;a <= num_of_days;a++) {
		
		cout << a; //prints all days of the month
		
		if (day != 6) {
			//it's not the end of the week, so places a new tab
			day++;
			cout << "\t";
		}
		else {
			//it's the ened of the week so we reset position for a new week
			day = 0;
			cout << endl;
		}
	}
	return day; 
	//returns the last day for the current month so the following month may pick up accordingly
}

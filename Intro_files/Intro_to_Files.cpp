// CS1_Files.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	
	ifstream myfile; myfile.open("infile.txt");string newname;
	
	string lastname,firstname, myname = "Brown, Travis";
	int comma_pos = 0;
	
	comma_pos = myname.find(',');
	cout << comma_pos << endl;
	
	lastname = myname.substr(0, comma_pos);
	cout << lastname << endl;
	
	firstname = myname.substr(comma_pos+2, myname.length());
	cout << firstname << endl;

	getline(myfile, newname, '\n');myname = newname;
	cout << myname << endl;

	comma_pos = newname.find(',');
	cout << comma_pos << endl;

	lastname = newname.substr(0, comma_pos);
	cout << lastname << endl;

	firstname = newname.substr(comma_pos+2,newname.length());
	cout << firstname << endl;

    return 0;
}
/*5
Brown
Travis
Brown, Travis
5
Brown
Travis
Press any key to continue . . .*/

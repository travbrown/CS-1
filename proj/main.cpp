#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

int main() {
	int numClasses;
	string first_name, last_name, class_ID;
	ifstream myfile;myfile.open("infile.txt");

	myfile >> first_name >> last_name;
	while (!myfile.eof()) {//termination test
		cout << "**************************************" << endl;
		cout << first_name <<" "<< last_name << endl;
		myfile >> numClasses;//reads in number of classes
		for (int count = 0;count < numClasses;count++) {//for loop ensures it attempts to read from the file the correct amount of times 
			myfile >> class_ID;
			cout << "\t\t" << class_ID << endl;
		}
		cout << "Number of Classes = " << numClasses;
		cout << "\n\n";
		myfile >> first_name >> last_name;
	}
	return 0;
}
/*
**************************************
Alkaline Vendetta
CSCI138
CSCI470
Number of Classes = 2

**************************************
Adidja Palmer
CSCI472
CSCI370
CSCI417
Number of Classes = 3

**************************************
Shabba Ranks
CSCI654
Number of Classes = 1

**************************************
Masicka Genahsyde
CSCI472
CSCI370
CSCI417
CSCI654
Number of Classes = 4

**************************************
Popcaan Unruly
CSCI472
CSCI370
Number of Classes = 2
*/
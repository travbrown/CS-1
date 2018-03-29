#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
ifstream myfile; 
void lookup_name(ifstream& myfile, string& last_name, string& cellnum);

int main() {
	string last_name, cellnum = ""; char again = 'y';
	while (again == 'y') {
		cout << "What's the last name of the person you're looking for: ";
		cin >> last_name;
		cout << endl;
		lookup_name(myfile, last_name, cellnum);
		if (cellnum != "") {
			cout << "The Cell number for the person you're looking for is " << cellnum << endl;
		}
		else {
			cout << "This person is not in the directory." << endl;
		}
		cout << "Do you want to look up another name in the directory? <y/n> " << endl;
		cin >> again;
	}
	return 0;
}
void lookup_name(ifstream& myfile, string& last_name, string& cellnum) {
	string fname, lname; 
	myfile.open("infile.txt");
	
	while (!myfile.eof()) { // until end of file is detected
		myfile >> fname >> lname >> cellnum; 
		if(lname == last_name){// if given last name matches the one in the directory
			break;
		}
		else {
			cellnum = "";
		}
	}
	myfile.close();
}
/*
What's the last name of the person you're looking for: Shurn

The Cell number for the person you're looking for is (410)560-8909
Do you want to look up another name in the directory? <y/n>
y
What's the last name of the person you're looking for: Kee

This person is not in the directory.
Do you want to look up another name in the directory? <y/n>
y
What's the last name of the person you're looking for: James

The Cell number for the person you're looking for is (301)123-3459
Do you want to look up another name in the directory? <y/n>
n
*/
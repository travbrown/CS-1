#include <iostream>
#include <string>
#include<iomanip>
#include <fstream>
using namespace std;
void switch_name(string&);
int main()
{
	ifstream my_file;
	string my_name;
	string last_name;
	string first_name;
	string new_name;
	int comma_pos = 0;
	my_file.open("infile.txt");
	string gpa;
	getline(my_file, my_name);
	getline(my_file, gpa);
	
	while (!my_file.eof()) {
		switch_name(my_name);
		cout << my_name << endl;

		getline(my_file, my_name);
		getline(my_file, gpa);
	}
	return 0;
}
void switch_name(string& name) {
	string fname,lname; int comma_pos;
	comma_pos = name.find(',');
	lname = name.substr(0, comma_pos);
	fname = name.substr(comma_pos + 2, name.length() - comma_pos + 1);
	name = fname + " " + lname;

}
/*
Harry Keeling
Money Big
Chance TheRapper
Dead Pool
*/
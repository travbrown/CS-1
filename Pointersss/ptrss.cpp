#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main() {
	int* intptr;
	float* floatptr;
	string *stringptr;
	
	intptr = new int;
	floatptr = new float;
	stringptr = new string;
	
	*intptr = 7;
	*floatptr = 2;
	*stringptr = "Travis ";

	cout << *intptr + *intptr << endl;
	cout << fixed << showpoint;
	cout << setprecision(2) << *floatptr * *floatptr << endl;
	cout << *stringptr + *stringptr << endl;

	return 0;
}
/*
14
4.00
Travis Travis
*/
#include <iostream>
#include <string>
#include<iomanip>
#include <fstream>
using namespace std;
//Function Prototypes (structure chart functions)
int Get_lab_data();
int Get_quiz_data();
int Get_test_data();
int Get_assignment_data();
char Compute_lab_grade();
char Compute_quiz_grade();
char Compute_test_grade();
char Compute_assignment_grade();
// global file variable
ifstream myfile;

int main()
{
	char lab_grade, quiz_grade, test_grade, assignment_grade;
	int student;

	myfile.open("infile.txt");
	while (myfile.eof()) {
		for (student = 1;student < 7;student++) {

			lab_grade = Compute_lab_grade();
			assignment_grade = Compute_assignment_grade();
			quiz_grade = Compute_quiz_grade();
			test_grade = Compute_test_grade();

			cout << "Student" << student << endl;
			cout << "Student's Lab grade is:" << lab_grade << endl;
			cout << "Student's Assignment grade is:" << assignment_grade << endl;
			cout << "Student's Quiz grade is:" << quiz_grade << endl;
			cout << "Student's Test grade is:" << test_grade << endl;
		}
	}
	myfile.close();
	return 0;
}

char Compute_lab_grade() {
	int total;
	total = Get_lab_data();

	if (total > 60) {
		return 'A';
	}
	else if (total >= 50) {
		return 'B';
	}
	else if (total >= 40) {
		return 'C';
	}
	else if (total >= 30) {
		return 'D';
	}
	else {
		return 'F';
	}
}
char Compute_assignment_grade() {
	int total;
	total = Get_test_data();
	if (total > 130) {
		return 'A';
	}
	else if (total >= 112) {
		return 'B';
	}
	else if (total >= 100) {
		return 'C';
	}
	else if (total >= 88) {
		return 'D';
	}
	else {
		return 'F';
	}
}
char Compute_quiz_grade() {
	int total;
	total = Get_assignment_data();

	if (total > 100) {
		return 'A';
	}
	else if (total >= 85) {
		return 'B';
	}
	else if (total >= 70) {
		return 'C';
	}
	else if (total >= 60) {
		return 'D';
	}
	else {
		return 'F';
	}
}
char Compute_test_grade() {
	int total;
	total = Get_quiz_data();

	if (total > 60) {
		return 'A';
	}
	else if (total >= 50) {
		return 'B';
	}
	else if (total >= 40) {
		return 'C';
	}
	else if (total >= 30) {
		return 'D';
	}
	else {
		return 'F';
	}
}

int Get_lab_data() {
	int i, grade, lab_score = 0;
	for (i = 0;i < 5;i++) {
		myfile >> grade;
		lab_score += grade;
	}
	return lab_score;
}
int Get_assignment_data() {
	int i, grade, assignment_score = 0;
	for (i = 0;i < 7;i++) {
		myfile >> grade;
		assignment_score += grade;
	}
	return assignment_score;
}
int Get_quiz_data() {
	int i, grade, quiz_score = 0;
	for (i = 0;i < 12;i++) {
		myfile >> grade;
		quiz_score += grade;
	}
	return quiz_score;
}
int Get_test_data() {
	int i, grade, test_score = 0;
	for (i = 0;i < 2;i++) {
		myfile >> grade;
		test_score += grade;
	}
	return test_score;
}

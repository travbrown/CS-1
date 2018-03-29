#include <iostream>
#include <string>
#include<iomanip>
#include <fstream>
using namespace std;
//Function Prototypes (structure chart functions)
int Get_lab_data();
int Get_quiz_data();
int Get_test_data();
float Get_final_data(char grade);
int Get_assignment_data();
char Compute_lab_grade();
char Compute_quiz_grade();
char Compute_test_grade();
char Compute_assignment_grade();
char Compute_final_grade(char lab_grade, char quiz_grade,char test_grade,char assignment_grade);
// global file variable
ifstream myfile;

int main()
{
	char lab_grade, quiz_grade, test_grade, assignment_grade, final_grade;
	int student;

	myfile.open("infile.txt");
	for (student = 1;student < 7;student++){

		lab_grade = Compute_lab_grade();
		assignment_grade = Compute_assignment_grade();
		quiz_grade = Compute_quiz_grade();
		test_grade = Compute_test_grade();
		final_grade = Compute_final_grade(lab_grade,quiz_grade,test_grade,assignment_grade);

		cout << "Student " << student << endl;
		cout << "Student's Lab grade is: " << lab_grade << endl;
		cout << "Student's Assignment grade is: " << assignment_grade << endl;
		cout << "Student's Quiz grade is: " << quiz_grade << endl;
		cout << "Student's Test grade is: " << test_grade << endl;		
		cout << "Student's Final grade is " << final_grade << endl;
		cout << "\n";
	
	}
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
	total = Get_assignment_data();
	if (total > 130) {
		return 'A';
	}
	else if (total >= 112) {
		return 'B';
	}
	else if (total >= 100) {
		return 'C';
	}
	else if (total >= 80) {
		return 'D';
	}
	else {
		return 'F';
	}
}
char Compute_quiz_grade() {
	int total;
	total = Get_quiz_data();

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
	total = Get_test_data();

	if (total > 360) {
		return 'A';
	}
	else if (total >= 210) {
		return 'B';
	}
	else if (total >= 180) {
		return 'C';
	}
	else if (total >= 150) {
		return 'D';
	}
	else {
		return 'F';
	}
}
char Compute_final_grade(char lab_grade, char quiz_grade, char test_grade, char assignment_grade) {
	float average; float lab, quiz, test, assignment;
	lab = Get_final_data(lab_grade);
	quiz = Get_final_data(quiz_grade);
	assignment = Get_final_data(assignment_grade);
	test = Get_final_data(test_grade);
	
	average = ((10 * quiz) + (25 * assignment) + (30 * lab) + (35 * test)) / 100;

	if (average > 3.49) {
		return 'A';
	}
	else if (average >= 2.7) {
		return 'B';
	}
	else if (average >= 1.7) {
		return 'C';
	}
	else if (average >= 0.7) {
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
	for (i = 0;i < 3;i++) {
		myfile >> grade;
		test_score += grade;
	}
	return test_score;
}
float Get_final_data(char grade) {
	int i;
	
	for (i = 0;i < 5;i++) {
		if (grade == 'A') {
			return 4.0;
		}
		else if (grade == 'B') {
			return 3.0;
		}
		else if (grade == 'C') {
			return 2.0;
		}
		else if (grade == 'D') {
			return 1.0;
		}
		else if (grade == 'F') {
			return 0.0;
		}
	}
}
/*
Student 1
Student's Lab grade is: F
Student's Assignment grade is: D
Student's Quiz grade is: F
Student's Test grade is: B
Student's Final grade is D

Student 2
Student's Lab grade is: B
Student's Assignment grade is: C
Student's Quiz grade is: B
Student's Test grade is: B
Student's Final grade is B

Student 3
Student's Lab grade is: C
Student's Assignment grade is: B
Student's Quiz grade is: F
Student's Test grade is: B
Student's Final grade is C

Student 4
Student's Lab grade is: C
Student's Assignment grade is: D
Student's Quiz grade is: F
Student's Test grade is: B
Student's Final grade is C

Student 5
Student's Lab grade is: C
Student's Assignment grade is: F
Student's Quiz grade is: D
Student's Test grade is: B
Student's Final grade is C

Student 6
Student's Lab grade is: B
Student's Assignment grade is: B
Student's Quiz grade is: C
Student's Test grade is: B
Student's Final grade is B
*/
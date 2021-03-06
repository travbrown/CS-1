#include "stdafx.h" //A library necessary for compilation on my pc
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
bool is_hung(int errors);
void heading();

int main()
{
	string question_set[6]; bool hung;
	char user_choice, answer; 
	int i, errors = 0;
	ifstream myfile;myfile.open("infile.txt"); //input stream and opening file
	heading();
	while ((myfile.eof()) || (hung != true)) { //will loop unitl end of file or if user becomes hung at any point
		
		cout << "\n******************************";
		cout << " MY HANG MAN GAME ";
		cout << "******************************\n\n";

		for (i = 0;i < 6;i++) { //Reads question, options and correct answer
			getline(myfile, question_set[i], '\n');
		}
		for (i = 0;i < 5;i++) {// prints all but line with correct answer
			if (i == 0) {
				cout << question_set[i] << endl << endl;
				continue;
			}
			cout << "\t" << question_set[i] << endl;
		}
		cout << "\n\tEnter the capital letter of your answer: ";
		cin >> user_choice; //collects the users answers
		answer = question_set[5].back(); //takes last letter from correct answer line which is the correct letter itself
		
		if (answer == user_choice) {
			cout << "CORRECT !!!!" << endl;
		}
		else {
			cout << "INCORRECT !!!!" << endl;
			errors += 1;
			hung = is_hung(errors);
		}
		// system commands were commented out for output to be achieved as it is
		system("pause"); //pauses system for the user to see results before next question
		system("cls"); //clears the screen
	}
	cout << "End of Game" << endl;
	myfile.close();
    return 0;
}
void heading(){
	string stars = "**********************************************************";
	cout << stars << "\nTravis J Brown\n@02822994\nFebruary 22, 2018"
		<< endl << "Lab 6" << endl
		<< "A Game of Hangman\n" << stars << endl;
}
bool is_hung(int errors) {
	if (errors == 7) {
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;
		cout << "\t \t \t" << "/ \\" << endl;
		cout << "\t YOU ARE HUNG!" << endl;
		return true;
	}else{
		if (errors == 6) {
			cout << "\t \t \t" << " O " << endl;
			cout << "\t \t \t" << "/|\\" << endl;
			cout << "\t \t \t" << " | " << endl;
			cout << "\t \t \t" << "/" << endl;
		}
		else if (errors == 5) {
			cout << "\t \t \t" << " O " << endl;
			cout << "\t \t \t" << "/|\\" << endl;
			cout << "\t \t \t" << " | " << endl;
		}
		else if (errors == 4) {
			cout << "\t \t \t" << " O " << endl;
			cout << "\t \t \t" << "/|\\" << endl;
		}
		else if (errors == 3) {
			cout << "\t \t \t" << " O " << endl;
			cout << "\t \t \t" << "/|" << endl;
		}
		else if (errors == 2) {
			cout << "\t \t \t" << " O " << endl;
			cout << "\t \t \t" << " |" << endl;
		}
		else if (errors == 1) {
			cout << "\t \t \t" << " O " << endl;
		}
	}

	return false;
}

/*
**********************************************************
Travis J Brown
@02822994
February 22, 2018
Lab 6
A Game of Hangman
**********************************************************

****************************** MY HANG MAN GAME ******************************

Question: What relational operator means greater than or equal to?

A Answer: >
B Answer: >=
C Answer: =>
D Answer: <

Enter the capital letter of your answer: C
INCORRECT !!!!
O

****************************** MY HANG MAN GAME ******************************

Question: What two values does a bool variable allow?

A Answer: 0 and 1
B Answer: True or false
C Answer: Yes and no
D Answer: 1 and 2

Enter the capital letter of your answer: B
CORRECT !!!!

****************************** MY HANG MAN GAME ******************************

Question: Which relational expression (where x is 4 and y is 8) is true?

A Answer: x = y
B Answer: x > y
C Answer: x < = y
D Answer: x >= y

Enter the capital letter of your answer: A
INCORRECT !!!!
O
|

****************************** MY HANG MAN GAME ******************************

Question: If we place an if statement within an if statement, we are creating a

A Answer: If-Then-Else statement
B Answer: Multiway branch
C Answer: If-Then-Else-If statement
D Answer: Nested control structure

Enter the capital letter of your answer: D
CORRECT !!!!

****************************** MY HANG MAN GAME ******************************

Question: The && and || operators are

Answer A: Binary operators
Answer B: Unary operators
Answer C: Secondary operators
Answer D: Primary operators

Enter the capital letter of your answer: A
CORRECT !!!!

****************************** MY HANG MAN GAME ******************************

Question: To find out if either the test grade is an A or the quiz grade is an A we would write the expression

Answer A: testGrade = `A' || quizGrade = `A'
Answer B: testGrade = `A' && quizGrade = `A'
Answer C: testGrade == `A' && quizGrade == `A'
Answer D: testGrade ==`A' || quizGrade == `A'

Enter the capital letter of your answer: S
INCORRECT !!!!
O
/|

****************************** MY HANG MAN GAME ******************************

Question: Which two pairs of expressions are equivalent?

A Answer: !(a == b) and a != b
B Answer: !(a == b) and a =! B
C Answer: (a == b)! and a != b
D Answer: (a == b)! and a =! B

Enter the capital letter of your answer: F
INCORRECT !!!!
O
/|\

****************************** MY HANG MAN GAME ******************************

Question: Which operator has the lowest precedence?

A Answer: &&
B Answer: ==
C Answer: ||
D Answer: =

Enter the capital letter of your answer: F
INCORRECT !!!!
O
/|\
|

****************************** MY HANG MAN GAME ******************************

Question: An assertion that must be true before a module is executed for the module to execute correctly is a

A Answer: Postcondition
B Answer: Precondition
C Answer: Priorcondition
D Answer: Subsequentcondition

Enter the capital letter of your answer: F
INCORRECT !!!!
O
/|\
|
/

****************************** MY HANG MAN GAME ******************************

Question: The While statement is different from the If statement because

A Answer: It is a looping structure
B Answer: It is used to repeat a course of action
C Answer: The statement is either skipped, executed once, or executed over and over
D Answer: All of the above

Enter the capital letter of your answer: D
CORRECT !!!!

****************************** MY HANG MAN GAME ******************************

Question: What are the two major types of loops?

A Answer: Count-controlled loops and event-controlled loops
B Answer: Sentinel-controlled loops and end-of-file-Controlled loops
C Answer: Sentinel-controlled loops and flag-controlled loops
D Answer: Count-controlled loops and flag-controlled loops

Enter the capital letter of your answer: R
INCORRECT !!!!
O
/|\
|
/ \
YOU ARE HUNG!
End of Game
Press any key to continue . . .
*/
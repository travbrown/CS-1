/*
Travis Brown
@02822994
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

void evaluate_cholesterol(int, int, string&, string&);
void evaluate_blood_pressure(int, int, string&, string&);
void print_blood_pressure(int Systolic_reading, int Diastolic_reading, string& Systolic_evaluation, string& Diastolic_evaluation);
void print_cholestrol(int HDL_reading, int LDL_reading, string& HDL_evaluation, string& LDL_evaluation);
int header();
void cholestrol();
void blood_pressure();
ifstream myfile;//instream for file

int main() {
	myfile.open("infile.txt");// opens file
	
	int num_of_records, visits;
	cout << "Enter the number of patient records: ";
	cin >> num_of_records;
	cout << fixed;
	//outer loop that control how many patient's data is read
	for (int i = 0; i < num_of_records;i++) {
		//prints the type of patient, their name and returns how many times they have visited the doctor
		visits = header();
		//inner loop adapts to loop the correct amount of Data Sets
		for (int a = 1; a <= visits; a++) {
			cout << "\nDATA SET " << a << endl;
			cholestrol();
			//evaluates and prints the cholestrol results for this data set
			blood_pressure();
			//evaluates and prints the blood pressure results for this data set
		};
	};
	
	myfile.close();//closes file
	return 0;
};

void evaluate_cholesterol(int HDL_reading, int LDL_reading, string& HDL_evaluation, string& LDL_evaluation) {
	if (HDL_reading >= 60) {
		HDL_evaluation = "Excellent";
	}
	else if (HDL_reading >= 40) {
		HDL_evaluation = "okay";
	}
	else {
		HDL_evaluation = "Too Low";
	}

	if (LDL_reading >= 190) {
		LDL_evaluation = "Very High";
	}
	else if (LDL_reading >= 160) {
		LDL_evaluation = "High";
	}
	else if (LDL_reading >= 130) {
		LDL_evaluation = "Borderline High";
	}
	else if (LDL_reading >= 100) {
		LDL_evaluation = "Near Optimal";
	}
	else{
		LDL_evaluation = "Optimal";
	}
}
void evaluate_blood_pressure(int Systolic_reading, int Diastolic_reading, string& Systolic_evaluation, string& Diastolic_evaluation) {
	if (Systolic_reading >= 180) {
		Systolic_evaluation = "Stage 3 Hypertension";
	}
	else if (Systolic_reading >= 160) {
		Systolic_evaluation = "Stage 2 Hypertension";
	}
	else if (Systolic_reading >= 140) {
		Systolic_evaluation = "Stage 1 Hypertension";
	}
	else if (Systolic_reading >= 130) {
		Systolic_evaluation = "Normal High";
	}
	else if (Systolic_reading >= 120) {
		Systolic_evaluation = "Normal";
	}
	else {
		Systolic_evaluation = "Optimal";
	}

	if (Diastolic_reading >= 110) {
		Diastolic_evaluation = "Stage 3 Hypertension";
	}
	else if (Diastolic_reading >= 100) {
		Diastolic_evaluation = "Stage 2 Hypertension";
	}
	else if (Diastolic_reading >= 90) {
		Diastolic_evaluation = "Stage 1 Hypertension";
	}
	else if (Diastolic_reading >= 85) {
		Diastolic_evaluation = "High Normal";
	}
	else if (Diastolic_reading >= 80) {
		Diastolic_evaluation = "Normal";
	}
	else{
		Diastolic_evaluation = "Optimal";
	};
}
void print_blood_pressure(int Systolic_reading, int Diastolic_reading, string& Systolic_evaluation, string& Diastolic_evaluation) {
	cout << "Blood Pressure Profile" << endl;
	cout << "Systolic: " << Systolic_reading << ", Diastolic: " << Diastolic_reading << endl;
	cout << "Systolic reading is " << Systolic_evaluation << endl;
	cout << "Diastolic reading is " << Diastolic_evaluation << endl;
}
void print_cholestrol(int HDL_reading, int LDL_reading, string& HDL_evaluation, string& LDL_evaluation) {
	cout << "Cholestrol Profile" << endl;
	cout << "HDL: " << HDL_reading << ", LDL: " << LDL_reading << endl;
	float ratio = (((HDL_reading) / 1.00) / LDL_reading);
	cout << "Ratio: " << setprecision(4) << ratio << endl;
	cout << "HDL is " << HDL_evaluation << endl;
	cout << "LDL is " << LDL_evaluation << endl;
	cout << "Ratio of HDL to LDL is ";
	if (ratio <= 0.3) {
		cout << "good" << endl;
	}
	else {
		cout << "not good" << endl;
	}
}
int header() {
	char patient_type; string patient_name; int visit_frequ;
	myfile >> patient_name >> patient_type >> visit_frequ;
	cout << "\n\n\n";
	cout << "***********************************************" << endl;
	if (patient_type == 'F') {
		cout << "Referral's Name - " << patient_name << endl;
	}
	else if (patient_type == 'C') {
		cout << "Current Patient's Name - " << patient_name << endl;
	}
	else if (patient_type == 'R') {
		cout << "Returning Patient's Name - " << patient_name << endl;
	}
	else if (patient_type == 'N') {
		cout << "New Patient's Name - " << patient_name << endl;
	};
	return visit_frequ;
}
void cholestrol() {
	string LDL_evaluation, HDL_evaluation; int LDL_reading, HDL_reading;
	myfile >> HDL_reading >> LDL_reading; // reads HDL & LDL values
	evaluate_cholesterol(HDL_reading, LDL_reading, HDL_evaluation, LDL_evaluation);
	//interprets the HDL & LDL values
	print_cholestrol(HDL_reading, LDL_reading, HDL_evaluation, LDL_evaluation);
	//communicates the conclusion of the evaluation

}
void blood_pressure() {
	string Systolic_evaluation, Diastolic_evaluation; int Systolic_reading, Diastolic_reading;
	myfile >> Systolic_reading >> Diastolic_reading; // reads Systolic & Diastolic values
	evaluate_blood_pressure(Systolic_reading, Diastolic_reading, Systolic_evaluation, Diastolic_evaluation);
	//interprets the Systolic & Diastolic values
	print_blood_pressure(Systolic_reading, Diastolic_reading, Systolic_evaluation, Diastolic_evaluation);
	//communicates the conclusion of the evaluation
}
/*
Enter the number of patient records: 4



***********************************************
Current Patient's Name - Jones

DATA SET 1
Cholestrol Profile
HDL: 60, LDL: 124
Ratio: 0.4839
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 130, Diastolic: 84
Systolic reading is Normal High
Diastolic reading is Normal

DATA SET 2
Cholestrol Profile
HDL: 65, LDL: 121
Ratio: 0.5372
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 133, Diastolic: 80
Systolic reading is Normal High
Diastolic reading is Normal

DATA SET 3
Cholestrol Profile
HDL: 70, LDL: 120
Ratio: 0.5833
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 130, Diastolic: 81
Systolic reading is Normal High
Diastolic reading is Normal



***********************************************
New Patient's Name - Smith

DATA SET 1
Cholestrol Profile
HDL: 30, LDL: 195
Ratio: 0.1538
HDL is Too Low
LDL is Very High
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 120, Diastolic: 85
Systolic reading is Normal
Diastolic reading is High Normal



***********************************************
Referral's Name - Williams

DATA SET 1
Cholestrol Profile
HDL: 45, LDL: 185
Ratio: 0.2432
HDL is okay
LDL is High
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 190, Diastolic: 112
Systolic reading is Stage 3 Hypertension
Diastolic reading is Stage 3 Hypertension

DATA SET 2
Cholestrol Profile
HDL: 50, LDL: 181
Ratio: 0.2762
HDL is okay
LDL is High
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 193, Diastolic: 115
Systolic reading is Stage 3 Hypertension
Diastolic reading is Stage 3 Hypertension



***********************************************
Returning Patient's Name - Foster

DATA SET 1
Cholestrol Profile
HDL: 55, LDL: 165
Ratio: 0.3333
HDL is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 163, Diastolic: 115
Systolic reading is Stage 2 Hypertension
Diastolic reading is Stage 3 Hypertension

DATA SET 2
Cholestrol Profile
HDL: 65, LDL: 145
Ratio: 0.4483
HDL is Excellent
LDL is Borderline High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 167, Diastolic: 95
Systolic reading is Stage 2 Hypertension
Diastolic reading is Stage 1 Hypertension

DATA SET 3
Cholestrol Profile
HDL: 57, LDL: 165
Ratio: 0.3455
HDL is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 163, Diastolic: 105
Systolic reading is Stage 2 Hypertension
Diastolic reading is Stage 2 Hypertension

DATA SET 4
Cholestrol Profile
HDL: 59, LDL: 163
Ratio: 0.3620
HDL is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 165, Diastolic: 108
Systolic reading is Stage 2 Hypertension
Diastolic reading is Stage 2 Hypertension
*/


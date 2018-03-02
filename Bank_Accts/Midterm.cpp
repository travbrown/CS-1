#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

void Print_report(char Acct_type,int Acct_no, float Acct_balance);
float Compute_Interest(char Acct_type, float Acct_minimum_balance, float Acct_balance);
float Compute_service_charge(char Acct_type, float Acct_minimum_balance, float Acct_balance);

int main() {
	
	ifstream myfile; myfile.open("infile.txt");
	char Acct_type; int Acct_no; 
	float service_charge, interest, Acct_minimum_balance, AC_balance;
	
	while(myfile >> AC_balance >> Acct_type >> Acct_minimum_balance >> Acct_no){
		
		service_charge = Compute_service_charge(Acct_type, Acct_minimum_balance, AC_balance);
		interest = Compute_Interest(Acct_type, Acct_minimum_balance, AC_balance);
		
		AC_balance -= service_charge;
		AC_balance += interest;
		Print_report(Acct_type, Acct_no, AC_balance);
	}
	
	myfile.close();
	return 0;
}
void Print_report(char Acct_type, int Acct_no, float Acct_balance) {
	string border = "***********************************************";
	cout << border << endl;
	
	cout << "Account Number: " << Acct_no << endl;
	if (Acct_type == 'S') {
		cout << "Account Type: Savings"<< endl;
	}
	else if (Acct_type == 'C') {
		cout << "Account Type: Checking" << endl;
	}
	cout << fixed << setprecision(2);
	cout << "Account Balance: " << Acct_balance << endl;

}
float Compute_Interest(char Acct_type, float Acct_minimum_balance, float Acct_balance) {
	if (Acct_balance >= Acct_minimum_balance) {
		if (Acct_type == 'S') {
			return (Acct_balance*0.04);
		}
		else if (Acct_type == 'C') {
			if ((Acct_balance - Acct_minimum_balance) >= 5000.00) {
				return (Acct_balance * 0.03);
			}
			else {
				return (Acct_balance * 0.05);
			}
		}
	}
	return 0;
}
float Compute_service_charge(char Acct_type, float Acct_minimum_balance, float Acct_balance) {
	if (Acct_balance < Acct_minimum_balance) {
		if (Acct_type == 'S') {
			return float(10.00);
		}
		else if (Acct_type == 'C') {
			return float(25.00);
		}
	}
	return 0;
}
/*
***********************************************
Account Number: 46728
Account Type: Savings
Account Balance: 2808.00
***********************************************
Account Number: 87324
Account Type: Checking
Account Balance: 7919.67
***********************************************
Account Number: 79873
Account Type: Savings
Account Balance: 790.00
***********************************************
Account Number: 89832
Account Type: Checking
Account Balance: 3150.00
***********************************************
Account Number: 98322
Account Type: Checking
Account Balance: 675.00
Press any key to continue . . .
*/
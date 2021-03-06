//#include "stdafx.h" //Use this library if necessary for your compiler
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

float compute_gross_pay(int, float, char); //function prototypes
float compute_taxes(float);
float compute_net_pay(float, float);
void print_pay_check(string, string, string, int, string, string, string, string, int, float, float, float);
float compute_federal_tax(float);
float compute_state_tax(float);
float compute_city_tax(float);
const string stars = "*********************************************************************************";

int main()
{
	string dummy; //declare variables
	char parttime_fulltime;
	float payRate, grossPay;
	float netPay;
	float totalTax;
	const string date = "02/16/2016";
	string last_name, first_name, street_address, street_name, street_type, city, state;
	int zip, deductions, employee_id, address_num;
	
	ifstream myfile;
	myfile.open("infile.txt"); // open infile;
	
	while(!myfile.eof())
	{
		myfile >> last_name >> first_name >> deductions >> employee_id >> address_num >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // get employee information

		grossPay = compute_gross_pay(deductions, payRate, parttime_fulltime);
		totalTax = compute_taxes(grossPay);
		netPay = compute_net_pay(grossPay, totalTax);

		print_pay_check(date, last_name, first_name, zip, street_name, street_type, city, state, address_num, netPay, grossPay, totalTax);
		
	}
	cout << stars << endl;
	myfile.close(); // close the file
	
	return 0; // return 0 if all works
}
float compute_gross_pay(int deductions, float payRate, char parttime_fulltime) {
	float gross_pay;
	gross_pay = 40 * payRate;
	if(parttime_fulltime == 'P'){
		gross_pay += (deductions * 10.5);
	}
	return gross_pay;
}
float compute_taxes(float grossPay) {
	float fedTax1 = 0, stateTax = 0, cityTax = 0;
	
	fedTax1 = compute_federal_tax(grossPay);
	if (fedTax1 >= 80) {
		stateTax = compute_state_tax(fedTax1);
		if (stateTax > 50) {
			cityTax = compute_city_tax(stateTax);
		}
	}	
	return (fedTax1 + stateTax + cityTax);
}
float compute_net_pay(float grossPay, float totalTax){
	return (grossPay - totalTax);
}
void print_pay_check(string date, string last_name, string first_name, int zip, string street_name, string street_type, string city, string state, int address_num, float netPay, float grossPay, float totalTax) {
	

	cout << stars << "\nABC Flowers\n123 Georgia Ave\t\t\t\t\t\t\t" << date
		<< "\nWashington, DC 20059" << endl;
	cout << fixed << setprecision(2);
	cout << "\nPayable to: \t" << last_name << " " << first_name
		<< "\t\tPay this amount: $" << netPay << "\n\t\t" << address_num
		<< " " << street_name << " " << street_type << "\n\t\t" << city << " " << state << " " << zip << endl;
	cout << "\nGross Pay: $" << grossPay << endl;
	cout << "Total Taxes: $" << totalTax << endl << endl;
	
}
float compute_federal_tax(float grossPay) {
	float fedTax = 0;
	
	if (grossPay > 500) {
		fedTax = (200 * 0.15) + (300 * 0.25) + ((grossPay - 500)*0.35);
	}	
		else if(grossPay > 200){
			fedTax = (200 * 0.15) + ((grossPay - 200) * 0.25);
		}
			else {
				fedTax = (grossPay * 0.15);
			}
	return fedTax;
}
float compute_state_tax(float fedTax) {
	return (fedTax * 0.1);
}
float compute_city_tax(float stateTax) {
	return (stateTax * 0.08);
}
/*
*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     Herold, Will            Pay this amount: $190.10
123 Main St.
Washington, DC 20019

Gross Pay: $226.80
Total Taxes: $36.70

*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     Jackson, Stan           Pay this amount: $342.45
12 Douglas Ave.
Baltimore, MD 30229

Gross Pay: $442.00
Total Taxes: $99.55

*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     Jerry, Francis          Pay this amount: $674.47
2345 6th Street
Woodbridge, VA 44040

Gross Pay: $971.50
Total Taxes: $297.03

*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     John, Wilson            Pay this amount: $323.60
12 Georgia Ave.
Washington, DC 20019

Gross Pay: $416.00
Total Taxes: $92.40

*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     Smith, Stanley          Pay this amount: $415.86
56 D Street
Baltimore, MD 30229

Gross Pay: $551.00
Total Taxes: $135.13

*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     Jeffers, Claude         Pay this amount: $1106.79
66 32nd Street
Woodbridge, VA 44040

Gross Pay: $1681.20
Total Taxes: $574.41

*********************************************************************************
ABC Flowers
123 Georgia Ave                                                 02/16/2016
Washington, DC 20059

Payable to:     Jeffers, Claude         Pay this amount: $1106.79
66 32nd Street
Woodbridge, VA 44040

Gross Pay: $1681.20
Total Taxes: $574.41

*********************************************************************************
Press any key to continue . . .


*/
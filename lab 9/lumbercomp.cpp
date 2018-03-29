#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

void get_user_input(char&, int&, int&, int&, int&);
float compute_item_cost(char&, int&, int&, int&, int&);

int main() {
	cout << fixed << showpoint;
	char wood_type='x'; 
	int num_pieces, width, height, length;
	float cost = 0, total = 0;
	get_user_input(wood_type, num_pieces, width, height, length);
	while (wood_type != 'T') {

		cost = compute_item_cost(wood_type, num_pieces, width, height, length);
		// compute the cost of the specific order
		total += cost;//sums up costs
		cout << num_pieces << " " << width << "X" << height << "X" << length;
		//Determines what type of lumber to print
		if (wood_type == 'P') {
			cout << " Pine, cost: $" << setprecision(2) << cost << endl;
		}
		else if (wood_type == 'F') {
			cout << " Fir, cost: $" << setprecision(2) << cost << endl;
		}
		else if (wood_type == 'C') {
			cout << " Cedar, cost: $" << setprecision(2) << cost << endl;
		}
		else if (wood_type == 'M') {
			cout << " Maple, cost: $" << setprecision(2) << cost << endl;
		}
		else if (wood_type == 'O') {
			cout << " Oak, cost: $" << setprecision(2) << cost << endl;
		};
		get_user_input(wood_type, num_pieces, width, height, length);
	};

	cout << "Total Cost: $" << setprecision(2) << total << endl;

	return 0;
}
void get_user_input(char& wood_type, int& num_pieces, int& width, int& height, int& length) {
	cout << "Enter item < Wood Type---No of pieces---Width---Height---Length >" << endl;
	cin >> wood_type;
	if (wood_type == 'T') { return; }//immediately returns if they enter T
	cin >> num_pieces >> width >> height >> length;
}
float compute_item_cost(char& type, int& quant, int& width, int& height, int& length) {
	float boardft = quant * ((width*height*length) / 12.0);
	if (type == 'P') {
		return 0.89*boardft;
	}
	else if (type == 'F') {
		return 1.09*boardft;
	}
	else if (type == 'C') {
		return 2.26*boardft;
	}
	else if (type == 'M') {
		return 4.50*boardft;
	}
	else if (type == 'O') {
		return 3.10*boardft;
	}
	else {
		return 0;
	}
}
/*
Enter item < Wood Type---No of pieces---Width---Height---Length >
P 10 2 4 8
10 2X4X8 Pine, cost: $47.47
Enter item < Wood Type---No of pieces---Width---Height---Length >
M 1 1 12 8
1 1X12X8 Maple, cost: $36.00
Enter item < Wood Type---No of pieces---Width---Height---Length >
T
Total Cost: $83.47
*/
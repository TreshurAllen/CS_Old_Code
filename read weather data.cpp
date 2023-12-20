#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double Highest;
double Lowest;
double avg_High;
double avg_Low;
double daily_Change;

struct weather_info { // structure  of state info
	double high;
	double low;
	double precip;
	double snow;
	double snowDepth;
};

void Get_info() { // grabs the line of text specifically needed
	weather_info info; 
	ifstream input_file;

	input_file.open("weather.txt"); // opens file

	double prevtempH = 0;
	double prevtempL = 50;
	double tempavgH;
	double tempavgL;
	double tempsnowD;

	
	int keeptrack;

	while (input_file >> info.high >> info.low >> info.precip >> info.snow >> info.snowDepth) {
		keeptrack += 1;
		if (info.high < prevtempH) {

		}
		else {
			prevtempH = info.high;
		}

		if (prevtempL > info.low) {

		}
		else {
			prevtempL = info.low;
		}

		tempavgH += info.high;
		tempavgL += info.low;

		if (keeptrack % 2) {
			daily_Change = info.snowDepth - tempsnowD;
			cout << "Average Daily Change: " << daily_Change << endl << endl;
		}
		else {
			tempsnowD = info.snowDepth;
		}
	}

	Highest	= prevtempH;
	Lowest = prevtempL;
	avg_High = (tempavgH / 31);
	avg_Low = (tempavgL / 31);

	input_file.close();
}

void nameheader();


int main() {
	Get_info();
	cout << "Highest Temp Recorded: " << Highest << endl;
	cout << "Lowest Temp Recorded: " << Lowest << endl;
	cout << "Average High: " << avg_High << endl;
	cout << "Average Low: " << avg_Low << endl;
    nameheader();
	return 0;
}

void nameheader()
    {
        cout << "\nCS120-04" << endl;
        cout << "Treshur Allen" << endl;
        cout << "HW 9" << endl;
        cout << "April 10, 2019" << endl;
    }



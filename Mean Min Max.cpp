/*Treshur Allen
  cs120-03
  asignment 8
  October 25, 2019 */

#include <iostream>
#include <cmath>
#include <numeric>
#include <stdlib.h>
using namespace std;

void generate(double*, int, double, double);
void print(double*, int);
double average(double*, int);
double min(double*, int);
double max(double*, int);
void addX(double*, int, double);
double num_less_1(double*, int);
double num_more(double*, int);
double num_less_1(double*, int, double);
double range(int, int);
double sum, ave_sum, lowest, highest, less_1, high, less_2;

int main() {
	int size = 100;
	double data[100];
	generate(data,100,-5.0,5.0);
	print(data,100);
	average(data,100);
	int a = min(data,100);
	int b = max(data,100);
	cout << "\nThe average is: " << ave_sum << "." << endl;
	cout << "The lowest number is: " << lowest << "." << endl;
	cout << "The highest number is: " << highest << "." << endl;
	addX(data,100,3);
	num_less_1(data,100);
	num_more(data,100);
	num_less_1(data,100,3);
	cout << "\nThere are " << less_1 << " numbers less than the average." << endl;
	cout << "There are " << high << " numbers above than the average." << endl;
	cout << "There are " << less_2 << " numbers below the treshold." << endl;
	cout << "The range is: " << range(a,b) << "." << endl;
}

void generate(double data[], int size, double lower, double upper) {
    for (int i = 0; i < size; i++) {
        data[i] = fmod(rand(),(upper-lower+1))+lower;
	}
}

void print(double data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << data[i];
	}
}

double average(double data[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum+=data[i];
	}
	ave_sum = sum/size;
	return ave_sum;
}

double min(double data[], int size) {
	for (int i = 0; i < size; i++) {
		if (data[i] < lowest){
			lowest = data[i];
		}
	}
	return lowest;
}

double max(double data[], int size) {
	for (int i = 0; i < size; i++) {
		if (data[i] > highest){
			highest = data[i];
		}
	}
	return highest;
}

void addX(double data[], int size, double value) {
	for(int i = 0; i < size; i++) {
		data[i] += value;
		cout << " " << data[i];
	}
}

double num_less_1(double data[], int size) {
	less_1 = 0;
	for(int i = 0; i < size; i++) {
		if (data[i] < ave_sum) {
			less_1 += 1;
		}
	}
	return less_1;
}

double num_more(double data[], int size) {
	high = 0;
	for(int i = 0; i < size; i++) {
		if (data[i] > ave_sum) {
			high += 1;
		}
	}
	return high;
}

double num_less_1(double data[], int size, double threshold) {
	less_2 = 0;
	for(int i = 0; i < size; i++) {
		if (data[i] < threshold) {
			less_2 += 1;
		}
	}
	return less_2;
}

double range(int max, int min) {
	int y = max - min;
	return y;
}
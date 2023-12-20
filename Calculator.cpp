#include <iostream>
using namespace std;

 /*	Treshur Allen
	cs 120-03
	Lab #3
	9-19-2019 */

int main(){

//------------------variable declaration---------------------
	int num1, num2, choice, specialcalc;
	double answer;
	char c;
	

	cout << "Welcome to the calculator program." << endl;
//------------------beginning loop---------------------------
	do{
		cout << "enter your first number(no decimels): ";
		cin >> num1;
		cout << "\nenter your second number(no decimels): ";
		cin >> num2;
		cout << "what would you like to do? " << endl;
		cout << "1 = add, 2 = subtract, 3 = multiply, 4 = divide," << endl;
		cin >> choice;
//---------------loop for invalid input-------------------

		while(choice < 1 || choice > 4)
		{
			cout << "Invalid input, try again: ";
			cin >> choice;
		}
		if(choice == 1){
			answer = num1 + num2;
			cout << num1 << " + " << num2 << " = " << answer;
		} 
		if(choice == 2){
			answer = num1 - num2;
			cout << num1 << " - " << num2 << " = " << answer;
		}
		if(choice == 3){
			answer = num1 * num2;
			cout << num1 << " * " << num2 << " = " << answer;
		}
		if(choice == 4){
			answer = num1 / num2;
			cout << num1 << " / " << num2 << " = " << answer;
		}

//------------------ending asking user to go again-----------------------

		cout << "\nwould you like to continue? (y or n): ";
		cin >> c;
	}while(c == 'y');
	cout << "\nThanks for using the calculator." << endl;
	return 0;

}

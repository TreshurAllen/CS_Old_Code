#include <iostream>
#include <string>
#include <stdio.h>  
#include <stdlib.h>     
#include <time.h>
using namespace std;

class pet{
    private:
        int hunger;
        int happy;
        string name;
        string species;
    public:
        pet();
        void play();
        void feed();
        void walk();
        void print();
        int check_health();
};
int main()
{
    pet pet1;
    int choice;
    int health_check;
    do{
        pet1.print();
        cout << "What would you like to do with your pet?\n";
        cout << " Play (1) \n Feed (2) \n Walk (3) \n Exit (0) \n";
        cin >> choice;
        switch(choice){
            case 1:
                pet1.play();
                break;
            case 2:
                pet1.feed();
                break;
            case 3:
                pet1.walk();
                break;
	    default:
		cout << "invalid choice, choose again" << endl;
		break;
        }
        health_check = pet1.check_health();
    }while(choice != 0 || health_check != 1);
    cin.ignore();
    cout << "Press enter to exit." << endl;
    cin.ignore();
    return 0;
}

pet::pet(){
    hunger = 50;
    happy = 50;
    cout << "Pet's name? (One word) ";
    cin >> name;
    cout << "\nWhat type of pet? (One word) ";
    cin >> species;
}
// the member function lets you play with the pet

void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n Dance (3) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
         break;
    case(2):
         happy += 5;
         hunger += 1;
         break;
    case(3):
        happy += 10;
        hunger += 10;
        break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

// lets you feed the pet
void pet::feed(){
    int option = 0;
    cout << "What would you like to feed your pet? dry food(1), treat(2), taco(3)" << endl;
    cin >> option;
    if (option == 1)
    {
        cout << "\nYAY FOOD!!\n";
        hunger -= 10;
    }
    else if (option == 2)
    {
        cout <<"\nMmm Yummy!\n";
        hunger -= 5;
        happy += 10;
    }
    else if (option == 3)
    {
        cout <<"\nOoo my tummy feels funny...\n";
        hunger -= 5;
        happy -= 5;
        
    }
}

void pet::walk(){
    int choice = 0;
    cout << "Where should we walk?\n";
    cout << " Street (1) \n Park (2) \n River (3) \n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "\nWow that was quick, but fun!\n";
        hunger += 5;
        happy += 5;
    }
    else if (choice == 2)
    {
        cout <<"\nI'm going to get the squirle!!\n";
        hunger += 10;
        happy += 10;
    }
    else if (choice == 3)
    {
        cout <<"\nHow pretty, I'm tired now..\n";
        hunger += 10;
        happy += 5;
        
    }
}


//prints out important info about the pet
void pet::print(){
    cout << "\nYour pet " << species << " " << name << " is ";
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    
}

// checks the health of the pet
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n"; //so hunger should be < 100 to be healthy
         cout << "You should've cared for them more :(" << endl;
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         cout << "Should have given them more attention" << endl;
         return 1;
    }
    return 0;
}








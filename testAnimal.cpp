/* testAnimal.cpp
 * CS 121.Bolden......g++...........Treshur Allen
 * Feb 14, 2020.......unix.laptop...alle0088@vandals.uidaho.edu
 *
 * description: the purpose of this program is to create a linkedlist 
 * of various animals with node manipulations through the integration 
 * of functions in the animal class. This program is to showcase our 
 * understanding of how linklist's work
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Animal_func.h" //Animal class and declarations
#include "Animal_class.h"   //Animals class functions
#include "animaldata2.h"

using namespace std;

int main(){
  string action;
  string type;

// read in the file


  ifstream data;
  data.open ("animaldata1.h");
  data >> action;

//create the animal object
  Animals list1;

  while(!data.eof()){  
	if( action == "add" ){
	  data >> type;
	  head -> list1.addNode(type);//run add function
	}
	elseif( action == "delete" ){
	  data >> type;
	  head -> list1.deleteNode(type);// delete function
	}
	elseif( action == "show"){
	  head -> list1.show();//pring function
	  head -> count();
	}
	else
	  cout << "Error";
	data >> action;
  }//end of while loop for list 1

  data.close();
  
  
  cout << endl << endl; //to create seperation between the lists 
    

  data.open("animaldata2.h");
  data >> action;

  Animals list2;

  while(!data.eof()){  
	if( action == "add" ){
	  data >> type;
	  head -> list1.addNode(type);//run add function
	}
	elseif( action == "delete" ){
	  data >> type;
	  head -> list1.deleteNode(type);// delete function
  	}
	elseif( action == "show"){
	  head -> list1.show();//pring function
	  head -> count();
	}
	else
	  cout << "Error";
	  data >> action;
  }//end of while loop for list 2
}//end of main

/*  qclass.h
 *
 * CS 121.Bolden.........putty g++...........Treshur Allen
 * 
 * this file holds the code for the queue class and its functions
 */


#include <iostream>
using namespace std;
#include "listQ.h"

typedef char sym;

class queue{

  private:
	linkedlist L;
  public:
	queue();  //constructer

	void enqueue( sym );
	int dequeue();

	int getfront();
	int getend();

	int sizeq();

	void print();
}; //end of class

//-------------function def-------------

queue::queue(){
  //default constructor
}

void queue::enqueue( sym newItem ){
  L.addnode( newItem );
}

int queue::dequeue(){
  int iVal;

  iVal = L.firstnode();
  L.deletenode();

  return iVal;
}

int queue::getfront(){
  L.firstnode();
}

int queue::getend(){
  return L.lastnode();
}

int queue::sizeq(){
  int length = L.size();
  return length;
}

void queue::print(){
  L.printnodes();
}


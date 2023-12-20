/*  listQ.h
 *
 * CS 121.Bolden.........putty g++...........Treshur Allen
 * 
 * this file holds the code for the linked list class & its functions
 */


#include <iostream>

class linkedlist{
  private :
	struct node{
	  char info;
	  node * next;
	};
	
	typedef node * nodeptr;

	nodeptr start;
	nodeptr end;
	int count;
  public:
    //constructor
	linkedlist(){	  
	  start = NULL;
	  end = start;
	  count = 0;
	}

	void addnode(char x);
	void deletenode();
	
	char firstnode();
	char lastnode();

	void printnodes();

	int size();
}; // end of class

void linkedlist::addnode(char x){
  nodeptr n = new node;
  n->info = x;
  n->next = NULL;
  count++;

  if( start == NULL ) {
	start = n;
	end = start;
  } else {
	end->next = n;
	end = end->next;
    }
}

void linkedlist::deletenode(){
  nodeptr curr;
  if( start != NULL ){
	curr = start;
	start = start->next;
	delete curr;
  }
}

char linkedlist::firstnode(){
  char iVal;
  if( start != NULL )
  iVal = start->info;

  return iVal;
}

char linkedlist::lastnode(){
  if( end != NULL )
  return end->info;
}

void linkedlist::printnodes(){
  nodeptr p = start;
  while( p != NULL ){
	cout << p->info << endl;
	p = p->next;
  }
}

int linkedlist::size(){

  return count;
}

  
  

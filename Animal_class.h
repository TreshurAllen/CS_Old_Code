/*  Animal_class.h
 *
 * CS 121.Bolden.........putty g++...........Treshur Allen
 * 
 * this file holds the code for the animal class 
 *and all the function declarations 
 */

#include <iostream>
#include <string>
 
using namespace std;
  struct node{
	string name;
	node * next;
  };
//     typedef struct node* nodePtr;


class Animals
{
  private:
     node* head;
     int count;

  public:
     Animals(){  //constructor inline
	head = NULL;
	count = 0;
     } // end of constructor 
   
   /*  ~Animals(){   //destructor inline
	node p = head;
	node n;
	while(p != NULL){
	  n = p;
	  p = p->next;
	  delete n;
	 }
      }//end of destructor  */

      void addNode(string x); // Delete the first node found with the value x, if one exists.
   
      void deleteNode(string x); // Output the values in the nodes, one integer per line. 

      void show(); // Return true if there in a node in the list with the value x.

//      int IsInList(string x); //checks if the input is in the list
 
//      int Size(); //returns the size of list 
};
    
       

void Animals::addNode(string x)
{
    node n, prev, curr;

    n = new node;
    n->name = x;
    count++;

    if (head == NULL)
    {
        head = n;
        n->next = NULL;
    }
    else
    {
        curr = head;
        while ( curr != NULL && x > curr->name )
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head)
        {
           n -> next = head;
           head = n;
        }
        else
        {
           prev->next = n;
           n -> next = curr;
        }
    }
}


void Animal::deleteNode(string x)
{
    node prev, curr;

    curr = head;

    while (curr != NULL && x > curr->name)
    {
        prev = curr;
        curr = curr->next;
    }

    if (x == curr->name)
    {
        if ( curr == head )
            head = head->next;
        else
            prev->next = curr->next;

        delete curr;
        count--;
    }
}


void Animals::show()
{
    node p = head;

    while (p != NULL)
    {
        cout << p->name << endl;
        p = p->next;
    }

}


int Animals::IsInList(string x)
{
    node p = head;

    while (p != NULL && x > p->name)
        p = p->next;

    return (x == p->name);
}


int Animals::Size()
{
    return count;
}
 



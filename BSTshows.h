/*  BSTshows.h
 *  CS 121.Bolden.........putty g++...........Treshur Allen
 *  Interface for Binary Search Tree class
 *  to hold all the info for the shows.txt file
 */

#include <iostream>
#include <string>
using namespace std;


//typedef int DATA_TYPE;  // original typedef for data

typedef string TITLE;  // title for show
typedef int YEAR;  // year for show
typedef string GENRE;  // type of show
typedef string ACT;  // actors/actresses for show


class BinarySearchTree {
  private:
    typedef struct  BSTreeNode {
//     DATA_TYPE     data;  ---->original 

       TITLE         Title;
       YEAR          Year;
       GENRE         Genre;
       ACT           Act;
       
       BSTreeNode   *leftPtr;
       BSTreeNode   *rightPtr;
    } *TreePtr;        //-------end of struct
    
    TreePtr rootPtr;   //  root of the BST
    
    void     InitBSTree(){ rootPtr = NULL; } //IN LINE FUNCTION
        
    void     PrintTitles( TreePtr treePtr ); // prints just titles 

    void     SearchShow( TreePtr treePtr, TITLE title ); // finds the given show then prints the actors in the show

    void     SearchAct( TreePtr treePtr, ACT act );  // finds the given actor and prints their shows
 
  public:
    BinarySearchTree(){ InitBSTree(); }  //inline constructor 
    
    bool     IsEmpty(){ return (rootPtr == NULL); }  //  inline
    
    void     AddNode( TITLE show, YEAR time, GENRE type, ACT actor );
    
    void     PrintShows();

    void     PrintActinShow( TITLE t );

    void     PrintShowsforAct( ACT a );
};

//------------------------------------------- declarations---------------------------------

// AddNode()           
//   Add (insert) new item into the BST, whose 
//   root node is pointed to by "rootPtr".  If 
//   the data already exists, it is ignored.

void BinarySearchTree::AddNode( TITLE show, YEAR time, GENRE type, ACT actor )
{
   TreePtr newPtr;

   newPtr = new BSTreeNode;
   // Adds all the info the function is given
   newPtr->Title     = show;
   newPtr->Year      = time;
   newPtr->Genre     = type;
   newPtr->Act       = actor;

   newPtr->leftPtr  = NULL;
   newPtr->rightPtr = NULL;
   
   //  If the BST is empty, insert the new data in root
   if( rootPtr == NULL )
   {
      rootPtr = newPtr;
   }
   else   //  Look for the insertion location
   {
      TreePtr   treePtr = rootPtr;
      TreePtr   targetNodePtr;
      
      while( treePtr != NULL )
      {
        targetNodePtr = treePtr;
        if( show == treePtr->Title ) 
           // Found same data; ignore it. 
           return;
        else if( show < treePtr->Title ) 
           // Search left subtree for insertion location
           treePtr = treePtr->leftPtr; 
        else   //  newData > treePtr->data 
           // Search right subtree for insertion location
           treePtr = treePtr->rightPtr; 
      }// end of loop

      //  "targetNodePtr" is the pointer to the
      //  parent of the new node.  Decide where 
      //  it will be inserted.
      if( show < targetNodePtr->Title )
         targetNodePtr->leftPtr = newPtr;
      else  // insert it as its right child
         targetNodePtr->rightPtr = newPtr;
   }// end of else
}  //end of function


//BinarySearchTree::TreePtr
void BinarySearchTree::SearchShow( TreePtr treePtr, TITLE title ) //-----------Private------
{
   if( treePtr != NULL )
   {
      if( title == treePtr->Title ) {   //loop for printing the array of actors
	 cout << "Here are the actors in " << title << ":" << endl;
         for(int i = 0; i<10; i++)
	   cout << treePtr->Act[i] << endl;
      }
      else if( title < treePtr->Title ) 
         // Search for "key" in left subtree
         SearchShow( treePtr->leftPtr, title );
      else   // (title > tree_ptr->title) 
         // Search for "show" in right subtree
         SearchShow( treePtr->rightPtr, title );
   }else{
      return;
   } 
} 

void BinarySearchTree::PrintActinShow( TITLE t )  // Public
{
  SearchShow( rootPtr, t);
}

// PrintShows() prints the title of the show in order
// ie root first / in order traversal

void BinarySearchTree::PrintShows() //    Public
{ 
    PrintTitle( rootPtr );
}

void BinarySearchTree::PrintTitle( TreePtr treePtr )  // private
{
   if( treePtr != NULL)
   {
     // Print left BST subtree
     PrintTitle( treePtr->leftPtr );
     // Print Root node data
     cout << treePtr->Title << endl;
     // Print right BST subtree
     PrintTitle( treePtr->rightPtr );
   }

   else 
     cout << "Nothing to print..." << endl;
}  // end of print function


void BinarySearchTree::SearchAct( TreePtr treePtr, ACT act ) //-----------Private------
{
   if( treePtr != NULL )
   {
      for(int i = 0; i < 10; i++){
        if( act == treePtr->Act[i] ) {   //loop for checking if actor is in show
    	   cout << act << " is in these shows: " << endl;
  	   cout << treePtr->Title << endl;
         }
      } // end of loop
   }
   SearchAct( treePtr->leftPtr, act );  //to search the rest of tree
   SearchAct( treePtr->rightPtr, act ); 
}

void BinarySearchTree::PrintShowsforAct( ACT a )  // Public
{
  SearchAct( rootPtr, a );
}



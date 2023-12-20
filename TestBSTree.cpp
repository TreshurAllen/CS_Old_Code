/* TestBSTree.cpp
 *
 *   CS 121.Bolden.........putty g++...........Treshur Allen
 *   Test Binary Search Tree (BST)
 */

#include <iostream>
#include <ifstream>
using namespace std;
#include "BSTshows.h"


int main(){

   ifstream infile;
   infile.open("shows.txt");
   TITLE title[100];
   YEAR year[100];
   Genre genre[100];
   ACT  actors[2000];
 
  BinarySearchTree  t1;
  for(int i = 0; i<100 ; i++)
   while (!inFile.eof()){
     inFile >> title[i] >> year[i] >> genre[i] << actors[i] << actors[i];
     t1.AddNode(title[i], year[i], genre[i], actors[i]);
    }
   
   t1.PrintShows();

   t1.PrintActinShow("The Saint");
   t1.PrintActinShow("Benson");
   t1.PrintActinShow("Dexter's Laboratory");
   t1.PrintActinShow("The Simpsons");
   t1.PrintActinShow("Animaniacs");

   t1.PrintShowsforAct("Tim Conway");
   t1.PrintShowsforAct("Clint Eastwood");
   t1.PrintShowsforAct("Marilu Henner");
   t1.PrintShowsforAct("Tress MacNeille");
   t1.PrintShowsforAct("Rainn Wilson");
   t1.PrintShowsforAct("William Conrad");

} // end of main

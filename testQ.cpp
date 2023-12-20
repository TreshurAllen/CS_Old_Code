/*  testQ.cpp
 *
 * CS 121.Bolden.........putty g++...........Treshur Allen
 * 
 * this file holds the code for the outputs 
 */


#include <iostream>
#include <fstream>

using namespace std;

#include "qclass.h"

class MAZE{
  char board_sym;
public:
  void fill( int file );
  void print();
  void visit( queue q , int&, int&);
}; //end of maze class

ifstream maze1("maze1.txt");
ifstream maze2("maze2.txt");
ifstream maze3("maze3.txt");


int main(){
  queue q1;

  int X1, Y1, X2, Y2, X3, Y3;
  maze1 >> X1;
  maze1 >> Y1;  

  MAZE M1[X1][Y1];

  for( int row = 0; row < X1; row++){
    for( int col = 0; col < Y1; col++){
	M1[row][col].fill(1);
    }
  }

  cout << "Here's your maze: " << endl;

  for(int row = 0; row < X1; row++){
    for(int col =0;col < Y1;col++)
	M1[row][col].print();
    cout << endl;
  }

// the start of the maze
  int x = 0;
  int y = 0;

cout << "Finding Path..." << endl;

// the end of the maze
  MAZE goal1 = M1[0][10];

//start of solving and building queue
  do{
   M1[x][y].visit(q1, x, y);
  }while( x != 0 && y != 10);

  int num1 = q1.sizeq();
  if(num1 == 0)
	cout << "This maze is unsolvable" << endl;
  else
	cout << "This maze took " << num1 << " steps." << endl; 

//-------------MAZE 2-----------------

  queue q2;
  maze2 >> X2;
  maze2 >> Y2;  

  MAZE M2[X2][Y2];

  for( int row = 0; row < X2; row++){
    for( int col = 0; col < Y2; col++){
	M2[row][col].fill(2);
    }
  }

  cout << "Here's your maze: " << endl;

  for(int row = 0; row < X2; row++){
    for(int col =0;col < Y2;col++)
	M2[row][col].print();
    cout << endl;
  }

// the start of the maze
  int a = 0;
  int b = 22;

cout << "Finding Path..." << endl;

// the end of the maze
  MAZE goal2 = M2[22][0];

//start of solving and building queue
  do{
   M2[a][b].visit(q2, a, b);
  }while( a != 22 && b != 22);

  int num2 = q2.sizeq();
  if(num2 == 0)
	cout << "This maze is unsolvable" << endl;
  else
	cout << "This maze took " << num2 << " steps." << endl;

//-----------Maze 3--------------------

  queue q3;
  maze3 >> X3;
  maze3 >> Y3;  

  MAZE M3[X3][Y3];

  for( int row = 0; row < X3; row++){
    for( int col = 0; col < Y3; col++){
	M3[row][col].fill(3);
    }
  }

  cout << "Here's your maze: " << endl;

  for(int row = 0; row < X3; row++){
    for(int col =0;col < Y3;col++)
	M3[row][col].print();
    cout << endl;
  }

// the start of the maze
  int c = 0;
  int d = 0;

cout << "Finding Path..." << endl;

// the end of the maze
  MAZE goal3 = M3[38][38];

//start of solving and building queue
  do{
   M3[c][d].visit(q3, c, d);
  }while( c != 38 && d != 38);

  int num3 = q3.sizeq();
  if(num3 == 0)
	cout << "This maze is unsolvable" << endl;
  else
	cout << "This maze took " << num3 << " steps." << endl;

}//end of main

//----------FUNCTIONS-----------
  
void MAZE::fill( int file ){
        if(file == 1)
          maze1 >> board_sym;

	if( file == 2)
	  maze2 >> board_sym;

	if(file == 3)
	  maze3 >> board_sym;

}// end of function
  
void MAZE::print(){
  cout << board_sym << " "; 
}

void MAZE::visit(queue q, int& x, int& y){
  char v = 'v'; 

  if(board_sym == '.'){
	q.enqueue(v);
	q.print();
  }
  else{
	x++;
	y++;
  }
}

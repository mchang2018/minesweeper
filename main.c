//main file of minesweeper program. Integrates all the other functions into minesweeper game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct_def.h"
#include "boards.h"
#include "move.h"
#include "win.h"


//Declare functions
void ReadCommandLineArgs(int argc, char** argv);
void PlayMineSweeper(int argc, char** argv);


//This function runs the game of minesweeper, integrating all the functions
void PlayMineSweeper(int argc, char** argv) {

   Board board;
   int action;    
   UserMove move; //row and col of move
   char result;   //win or lose

   if (argc == 5) {
      srand(atoi(argv[4]));
   }
   else {
      srand((int)time(0));
   }

   CreateBoard(argv, &board); //create playing board as specified by user + a border, then hide all tiles
   PlaceMines(&board);        //place specified number of mines on the board
   BoardNumbers(&board);      //count number of mines around each tile

   do {
      printf("There are %d mines left\n", board.num_mines);
      DisplayBoard(board);
      GetAction(board, &move, &action);       //ask user what tile they want to play on and what action to take
      ImplementAction(&board, action, move);  //reveal appropriate tiles

   } while (!GameOver(board, move, &result));

   RevealBoard(board);  //reveal everything on the board
   DisplayBoard(board);
   DeclareWinner(result);
   //DeleteBoard(board);
} 


void ReadCommandLineArgs(int argc, char** argv) {

	if (argc > 5) {
      printf("Too many arguments. Usage:\n");
		printf("./mine_sweeper.out num_rows num_cols num_mines [seed])");
		exit(0);
	}
	if (argc < 4) {
		printf("Not enough arguments. Usage:\n");
      printf("./mine_sweeper.out num_rows num_cols num_mines [seed])");
      exit(0);
	}
}


int main(int argc, char** argv) {

	ReadCommandLineArgs(argc, argv);
   PlayMineSweeper(argc, argv);
   return 0;
}
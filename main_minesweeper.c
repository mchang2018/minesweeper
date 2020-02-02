//main file of minesweeper program. Integrates all the other functions into minesweeper game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct_def.h"
#include "boards.h"


//Declare functions
void ReadCommandLineArgs(int argc, char** argv);
void PlayMineSweeper(int argc, char** argv);


void PlayMineSweeper(int argc, char** argv) {

   Board board;

   if (argc == 5) {
      srand(atoi(argv[4]));
   }
   else {
      srand((int)time(0));
   }

   CreateBoard(argv, &board); //create playing board as specified by user + a border, then hide all tiles
   PlaceMines(&board);        //place specified number of mines on the board
   BoardNumbers(&board);      //count number of mines around each tile
   DisplayBoard(board);

   /*do {
      printf("There are %c mines left\n", board.num_mines);
      DisplayBoard(board);
      GetMove(&board);
      PlayMove(&board, &display_board);

   } while (!GameOver(board));

   DisplayBoard(display_board);
   DeclareResult(board);
   DeleteBoard(board);
   DeleteBoard(display_board); */
} 


void ReadCommandLineArgs(int argc, char** argv) {

	if (argc > 5) {
		printf("Usage mine_sweeper.out num_rows num_columns number_of_mines seed\n");
		exit(0);
	}
	if (argc < 4) {
		printf("Usage mine_sweeper.out num_rows num_columns number_of_mines seed\n");
      exit(0);
	}
}


int main(int argc, char** argv) {

	ReadCommandLineArgs(argc, argv);
   PlayMineSweeper(argc, argv);
   return 0;
}
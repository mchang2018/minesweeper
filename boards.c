//This file contains functions that relate to manipulating the playing board

#include <stdio.h>
#include <stdlib.h>
#include "boards.h"
#include "struct_def.h"


//frees up the space taken up by board
void DeleteBoard(Board* board) {
   int row;
   for (row = 0; row < board->num_rows + 2; row++) {
      free(board->the_board[row]);
   }
   free(board->the_board);
}


//this function reveals all the tiles on the board
void RevealBoard(Board board) {

   int row, col;

   for (row = 1; row <= board.num_rows; row++) {
      for (col = 1; col <= board.num_cols; col++) {
         board.the_board[row][col].visibility = 4;
      }
   }
}


//this function displays the board
void DisplayBoard(Board board) {

   int row, col;

   for (row = 1; row <= board.num_rows; row++) {
      printf("%d ", board.num_rows - row);
      for (col = 1; col <= board.num_cols; col++) {

         if (board.the_board[row][col].visibility == 0) {  //visisbility = 0 means board is hdden
            printf("# ");
         }
         else if (board.the_board[row][col].visibility == 1) { //1 means marked
            printf("! ");
         }
         else if (board.the_board[row][col].visibility == 2) {  //2 means questioned
            printf("? ");
         }
         else if (board.the_board[row][col].visibility == 4 && board.the_board[row][col].num_mines_around == -1) {  //4 means revealed, -1 means mine
            printf("* ");
         }
         else if (board.the_board[row][col].visibility == 4) {
            printf("%d ", board.the_board[row][col].num_mines_around);
         }
      }
      printf("\n");
   }
   printf("  ");
   for (col = 1; col <= board.num_cols; col++) {
      printf("%d ", col - 1);
   }
   printf("\n");
}


//counts the number of mines around a tile and then assigns that value to the tile itself
int CountMinesAroundTile(Board board, int row, int col) {

   int i, j;
   int mine_counter = 0;

   for (i = row - 1; i <= row + 1; i++) {    //counts all tiles around 
      for (j = col - 1; j <= col + 1; j++) {

         if (i == row && j == col) {
            continue;
         }
         if (board.the_board[i][j].num_mines_around == -1) {
            mine_counter++;
         }
      }
   }
   return mine_counter;
}


//assigns every tile a value of the number of mine around it
void BoardNumbers(Board* board) {

   int row, col;

   for (row = 1; row <= board->num_rows; row++) {
      for (col = 1; col <= board->num_cols; col++) {

         if (board->the_board[row][col].num_mines_around == -1) {  //if that tile contains a mine, move on
            continue;
         }
         board->the_board[row][col].num_mines_around = CountMinesAroundTile(*board, row, col);
      }
   }
}


//place mines in random locations on board
void PlaceMines(Board* board) {

   int i;
   int mine_row, mine_col;

   for (i = 0; i < board->num_mines; i++) {
      do {
         mine_row = rand() % board->num_rows;
         mine_col = rand() % board->num_cols;
      }
      while (board->the_board[board->num_rows - mine_row][mine_col + 1].num_mines_around == -1); //-1 means tile already contains a mine

      printf("Placing mine at %d, %d\n", mine_row, mine_col);
      board->the_board[board->num_rows - mine_row][mine_col + 1].num_mines_around = -1; //place mine on the randomly generated location
   }
}


//create playing board
void CreateBoard(char** argv, Board* board) {

   int row, col;

   board->num_rows = atoi(argv[1]);
   board->num_cols = atoi(argv[2]);
   board->num_mines = atoi(argv[3]);

   board->the_board = (Tile**)malloc((board->num_rows + 2) * sizeof(Tile*));  //2 extra rows and col in order to add a border around the actual playing board

   for (row = 0; row < (board->num_rows) + 2; row++) {

      board->the_board[row] = (Tile*)malloc((board->num_cols + 2) * sizeof(Tile));

      for (col = 0; col < (board->num_cols) + 2; col++) {

         board->the_board[row][col].visibility = 0;  //hide all tiles
      }
   }
}


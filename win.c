//This file contains functions checking whether the game is over and who won or lost

#include <stdio.h>
#include <stdlib.h>
#include "struct_def.h"
#include "win.h"


//Declares whether user won or lost
void DeclareWinner(char result) {

   if (result == 'w') {
      printf("You Won!!\n");
   }
   else {
      printf("You Lost :(\n");
   }
}


//checks whether all the mines are marked
bool MinesFlagged(Board board) {

   int row, col;

   for (row = 1; row <= board.num_rows; row++) {
      for (col = 1; col <= board.num_cols; col++) {

         if (board.the_board[row][col].num_mines_around != -1) {
            continue;
         }
         if (board.the_board[row][col].visibility != 1) {  //if a mine isn't marked, return false
            return false;
         }
      }
   }
   return true;
}


//checks that all the tiles that don't contain mines have been revealed
bool NonMineTilesRevealed(Board board) {

   int row, col;

	for (row = 1; row <= board.num_rows; row++) {
      for (col = 1; col <= board.num_cols; col++) {

         if (board.the_board[row][col].num_mines_around == -1) {
            continue;
         }
         if (board.the_board[row][col].visibility != 4) {
            return false;
         }
      }
   }
   return true;
}


//if user move corresponds to a tile that contains a mine, they lose
bool GameLost(Board board, UserMove move, char* result) {

	if (board.the_board[move.move_row][move.move_col].num_mines_around == -1 && board.the_board[move.move_row][move.move_col].visibility == 4) {
      *result = 'l';
      return true;
   }
   else {
      return false;
   }
}


bool GameWin(Board board, char* result) {

	if (NonMineTilesRevealed(board) && MinesFlagged(board)) {  //if all mines are flagged and non-mine tiles are revealed, they win
      *result = 'w';
      return true;
   }
   else {
      return false;
   }
}


bool GameOver(Board board, UserMove move, char* result) {

	return GameWin(board, result) || GameLost(board, move, result);
}

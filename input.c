//This file contains functions that check for valid user input

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "struct_def.h"
#include "input.h"


bool ValidAction(Board board, UserMove move, int action) {
   if (board.the_board[move.move_row][move.move_col].visibility == 0) {
      return action == 0 || action == 1 || action == 2 || action == 3;
   }
   else {
      return action == 0 || action == 1;
   }
}


bool MoveConstraintsMet(Board board, UserMove move) {
   return move.move_row < board.num_rows && move.move_col < board.num_cols && move.move_row >= 0 && move.move_col >= 0;
}


//checks to see if format of last scanf performed is valid
bool IsValidFormatting(int numArgsRead, int numArgsNeeded) {
   bool validFormat = (numArgsRead == numArgsNeeded);  
   char lastChar;  

   do {                          
      scanf("%c", &lastChar);    
      if (!isspace(lastChar)) {  //something besides white space appeared after expected input
         validFormat = false;    
      }
   }
   while (lastChar != '\n');     //search until end of line
   return validFormat;
}


bool IsValidMove(int numArgsRead, int numArgsNeeded, Board board, UserMove move) {
	return IsValidFormatting(numArgsRead, numArgsNeeded) && MoveConstraintsMet(board, move);
}



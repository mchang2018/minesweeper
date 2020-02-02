//This file contains functions pertaining to getting and implementing action by user

#include <stdio.h>
#include <stdlib.h>
#include "struct_def.h"
#include "input.h"
#include "move.h"


//recursive function to reveal all appropriate tiles
void RevealTiles(Board* board, int row, int col) {    

   int i, j;

   if (row < 1 || row > board->num_rows || col < 1 || col > board->num_cols) {  //stop when going out of bounds
      return;
   }
   if (board->the_board[row][col].visibility != 0) {  //stop if tile is not concealed
      return;
   }
   else if (board->the_board[row][col].num_mines_around != 0) { //reveal and then stop if tile has 1 more more mines around it
      board->the_board[row][col].visibility = 4;
   }
   else {
      board->the_board[row][col].visibility = 4;  //reveal and then run function again on all tiles around it if there are 0 mines
      for (i = row - 1; i <= row + 1; i++) {
         for (j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
               continue;
            }
            RevealTiles(board, i, j);
         }
      }
   }
}


//implements the user action on tile
void ImplementAction(Board* board, int action, UserMove move) { 

   if (board->the_board[move.move_row][move.move_col].visibility == 0) {  //for hidden tiles, either reveal, mark, or question tiles based on action
      if (action == 0) {
         RevealTiles(board, move.move_row, move.move_col);
      }
      else if (action == 1) {
         board->the_board[move.move_row][move.move_col].visibility = 2;  
      }
      else if (action == 2) {
         board->the_board[move.move_row][move.move_col].visibility = 1;  
         board->num_mines = board->num_mines - 1;  //the counter for number of mines remaining goes down everytime user marks a tile
      }
   }
   else if (board->the_board[move.move_row][move.move_col].visibility == 1) {  //unmark or unquestion tile
      board->the_board[move.move_row][move.move_col].visibility = 0;
      board->num_mines = board->num_mines + 1;  //the counter for number of mines remaining goes up everytime user unmarks a tile
   }
   else if (board->the_board[move.move_row][move.move_col].visibility == 2) {
      board->the_board[move.move_row][move.move_col].visibility = 0;
   }
}


//Asks user for tile they want to take action on and check if it's valid
void GetMove(Board board, UserMove* move) {

	int numArgsRead;

	do {
      printf("Enter row a row between 0-%d and a column between 0-%d: ", board.num_rows - 1, board.num_cols - 1);
      numArgsRead = scanf("%d %d", &(move->move_row), &(move->move_col));

	} while (!IsValidMove(numArgsRead, 2, board, *move));

      move->move_row = board.num_rows - move->move_row;  //convert the user row and col to the appropriate row and col corresponding to location on board
      move->move_col = move->move_col + 1;
}


//Give user appropriate action options depending on visibility of tile they selected
void GetAction(Board board, UserMove* move, int* action) {

   do {
      GetMove(board, move);  

      if (board.the_board[move->move_row][move->move_col].visibility == 0) {  //if tile is still hidden give them 4 options
         printf("Enter Action\n");
         printf("0. Reveal\n1. Question\n2. Mark\n3. Cancel\n");
         printf("Action: ");
         scanf("%d", action);
      }
      else if (board.the_board[move->move_row][move->move_col].visibility == 1) {  //if tile is marked or questioned, they can unmark/question it or cancel
         printf("Enter Action\n");
         printf("0. UnMark\n1. Cancel\n");
         printf("Action: ");
         scanf("%d", action);
      }
      else if (board.the_board[move->move_row][move->move_col].visibility == 2) {
         printf("Enter Action\n");
         printf("0. UnQuestion\n1. Cancel\n");
         printf("Action: ");
         scanf("%d", action);
      }
      else {
         printf("This tile is already revealed.\n");
      }
   } while ((board.the_board[move->move_row][move->move_col].visibility == 0 && *action == 3) ||   //while user hasn't canceled and action is valid
           (board.the_board[move->move_row][move->move_col].visibility == 1 && *action == 1)  ||
           (board.the_board[move->move_row][move->move_col].visibility == 2 && *action == 1)  ||
            board.the_board[move->move_row][move->move_col].visibility == 4 || !ValidAction(board, *move, *action)); 
}

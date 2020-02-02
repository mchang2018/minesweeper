#ifndef STRUCT_DEF_H
	#define STRUCT_DEF_H

	typedef struct Tile_struct {
	   int visibility;
	   int num_mines_around;
	} Tile;


	typedef struct Board_struct {
	   int num_rows;
	   int num_cols;
	   int num_mines;
	   Tile** the_board;
	} Board;


   typedef struct UserMove_struct {
      int move_row;
      int move_col;
   } UserMove;

#endif
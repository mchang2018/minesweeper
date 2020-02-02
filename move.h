#ifndef MOVE_H
   #define MOVE_H
   
   #include "struct_def.h"

	void GetMove(Board board, UserMove* move);
	void GetAction(Board board, UserMove* move, int* action);
	void ImplementAction(Board* board, int action, UserMove move);
	void RevealTiles(Board* board, int row, int col);

#endif
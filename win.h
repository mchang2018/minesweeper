#ifndef WIN_H
	#define WIN_H

	#include <stdbool.h>
	#include "struct_def.h"

	bool GameOver(Board board, UserMove move, char* result);
	bool GameLost(Board board, UserMove move, char* result);
	bool GameWin(Board board, char* result);
	bool NonMineTilesRevealed(Board board);
	bool MinesFlagged(Board board);
	void DeclareWinner(char result);

#endif
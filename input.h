#ifndef INPUT_H
	#define INPUT_H

   #include <stdbool.h>
   #include "struct_def.h"

   bool IsValidMove(int numArgsRead, int numArgsNeeded, Board board, UserMove move);
   bool IsValidFormatting(int numArgsRead, int numArgsNeeded);
   bool MoveConstraintsMet(Board board, UserMove move);
   bool ValidAction(Board board, UserMove move, int action);

#endif
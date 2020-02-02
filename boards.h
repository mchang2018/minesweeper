#ifndef BOARDS_H
   #define BOARDS_H
   
   #include "struct_def.h"

   void CreateBoard(char** argv, Board* board);
   void PlaceMines(Board* board);
   void BoardNumbers(Board* board);
   int CountMinesAroundTile(Board board, int row, int col);
   void DisplayBoard(Board board);
   void RevealBoard(Board board);
   void DeleteBoard(Board* board);

#endif
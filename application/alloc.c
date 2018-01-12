/**
 * @file alloc.c
 * @brief Handles (de)allocation of the chess board
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <stdlib.h>
#include "alloc.h"

int** allocBoard(const int iSize)
{
   int **ppiBoard = (int **) calloc(iSize, sizeof(int *));

   if (!ppiBoard)
   {
      return NULL;
   }

   for (int i = 0; i < iSize; ++i)
   {
      ppiBoard[i] = (int *) calloc(iSize, sizeof(int *));

      if (!ppiBoard[i])
      {
         return NULL;
      }
   }

   return ppiBoard;
}

void freeBoard(int **ppiBoard, const int iSize)
{
   for (int i = 0; i < iSize; ++i)
   {
      free(ppiBoard[i]);
   }

   free(ppiBoard);
}

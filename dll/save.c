/**
 * @file save.c
 * @brief Handles saving solutions to a file
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <stdio.h>
#include "save.h"

/**
 * @brief The character representing an empty field
 */
#define SAVE_CHAR_NONE  '#'

/**
 * @brief The character representing a queen
 */
#define SAVE_CHAR_QUEEN 'Q'

void resetFile(const char * const pcFilename)
{
   FILE *pFile;

   pFile = fopen(pcFilename, "w");

   if (pFile)
   {
      fclose(pFile);
   }
}

int appendToFile(const char * const pcFilename, const int ** const ppiBoard, const int iSize, const int iSolutionCount)
{
   FILE *pFile;

   pFile = fopen(pcFilename, "a");

   if (!pFile)
   {
      return 0;
   }

   fprintf(pFile, "Solution %d for %dx%d\n", iSolutionCount, iSize, iSize);

   for (int iR = 0; iR < iSize; ++iR)
   {
      for (int iC = 0; iC < iSize; ++iC)
      {
         if (ppiBoard[iR][iC])
         {
            fprintf(pFile, " %c", SAVE_CHAR_QUEEN);
         }
         else
         {
            fprintf(pFile, " %c", SAVE_CHAR_NONE);
         }
      }

      fprintf(pFile, "\n");
   }

   fprintf(pFile, "\n");

   fclose(pFile);

   return 1;
}

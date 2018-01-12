/**
 * @file nqueens.h
 * @brief Contains the nQueens struct and the enums and structs it is using.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _NQUEENS_H_
#define _NQUEENS_H_

#include <time.h>

/**
 * @brief The default board size
 */
#define DEFAULT_BOARD_SIZE 4

/**
 * @brief The default filename
 */
#define DEFAULT_FILENAME   "default.txt"

/**
 * @brief Application modes step and continuous
 */
enum AppMode
{
   Step,
   Continuous,
};

/**
 * @brief Save modes on and off
 */
enum SaveMode
{
   SaveOn,
   SaveOff,
};

/**
 * @brief Runtime measurement data
 */
struct AppTime
{
   clock_t lLastTimeStamp;
   double dRuntime;
};

/**
 * @brief Complex data type for solving the n queens problem
 */
struct nQueens
{
   /** @brief The chess board */
   int **ppiBoard;
   /** @brief The size of the chess board */
   int iSize;
   /** @brief The filename to save solutions */
   char acFilename[64];

   /** @brief The current app mode */
   enum AppMode eAppMode;
   /** @brief The current save mode */
   enum SaveMode eSaveMode;
   /** @brief Whether the app should close */
   int iShouldClose;
   /** @brief Whether the app should solve */
   int iShouldSolve;

   /** @brief Data related to runtime measurements */
   struct AppTime sAppTime;

   /** @brief The current solution count */
   int iSolutionCount;
};

/**
 * @brief Initializes the nQueens struct with default values
 * @param psnQueens The instance to initialize
 * @author Paul Meffle
 * @date 04.01.2018
 */
void init(struct nQueens * const psnQueens);

/**
 * @brief Resets the chess board with all zeros
 * @param ppiBoard The array to reset
 * @param iSize The size of the array
 * @author Paul Meffle
 * @date 04.01.2018
 */
void resetBoard(int ** const ppiBoard, const int iSize);

#endif // _NQUEENS_H_

/**
 * @file print.h
 * @brief Contains function declarations of the print module.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _PRINT_H_
#define _PRINT_H_

struct nQueens;

/**
 * @brief Prints the header, menu and status line
 * @param psnQueens The current app state for the status line
 * @author Paul Meffle
 * @date 04.01.2018
 */
void print(const struct nQueens * const psnQueens);

/**
 * @brief Prints the header, message pcMessage and status line
 * @param pcMessage The message to print
 * @param psnQueens The current app state for the status line
 * @author Paul Meffle
 * @date 04.01.2018
 */
void printMessage(const char *pcMessage, const struct nQueens * const psnQueens);

/**
 * @brief Prints the chess board ppiBoard with ascii characters
 * @param ppiBoard The array to print
 * @param iN The size of the array
 * @author Paul Meffle
 * @date 04.01.2018
 */
void printBoard(int ** const ppiBoard, const int iSize);

/**
 * @brief Prints the solution count iSolutionCount centered
 * @param iSolutionCount The solution count to print
 * @author Paul Meffle
 * @date 04.01.2018
 */
void printSolutionCount(const int iSolutionCount);

/**
 * @brief Prints the current app state as a status line
 * @param psnQueens The current app state
 * @author Paul Meffle
 * @date 04.01.2018
 */
void printStatus(const struct nQueens * const psnQueens);

#endif // _PRINT_H_

/**
 * @file input.h
 * @brief Contains function declarations of the input module.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _INPUT_H_
#define _INPUT_H_

#include "nqueens.h"

/**
 * @brief Waits for input and reacts to it
 * @param psnQueens Used to store several flags affected by input
 * @author Paul Meffle
 * @date 04.01.2018
 */
void awaitInput(struct nQueens * const psnQueens);

/**
 * @brief Waits for input inside the solve function and reacts to it
 * @param psnQueens Used to store several flags affected by input
 * @author Paul Meffle
 * @date 04.01.2018
 */
void awaitInputSolve(struct nQueens * const psnQueens);

/**
 * @brief Checks for input inside the solve function and reacts to it
 * @param psnQueens Used to store several flags affected by input
 * @author Paul Meffle
 * @date 04.01.2018
 */
void checkInputSolve(struct nQueens * const psnQueens);

#endif // _INPUT_H_

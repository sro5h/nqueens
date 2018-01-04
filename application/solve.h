/**
 * @file solve.h
 * @brief Contains function declarations of the solve module.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _SOLVE_H_
#define _SOLVE_H_

#include "nqueens.h"

/**
 * @brief Recursively solves the n queens problem
 * @param iRow The current row
 * @param psnQueens The struct to store the solution data in
 * @return Whether the problem was solved successfully, -1 if not
 * @author Paul Meffle
 * @date 04.01.2018
 */
int solve(const int iRow, struct nQueens * const psnQueens);

#endif // _SOLVE_H_

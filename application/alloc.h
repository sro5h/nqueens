/**
 * @file alloc.h
 * @brief Contains function declarations of the alloc module.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _ALLOC_H_
#define _ALLOC_H_

/**
 * @brief Allocates a two dimensional array of size iSize
 * @param iSize The size of the array
 * @return A pointer to the allocated array
 * @author Paul Meffle
 * @date 04.01.2018
 */
int** allocBoard(const int iSize);

/**
 * @brief Frees a tow dimensional array of size iSize
 * @param ppiBoard The array to free
 * @param iSize The size of the array
 * @author Paul Meffle
 * @date 04.01.2018
 */
void freeBoard(int** ppiBoard, const int iSize);

#endif // _ALLOC_H_

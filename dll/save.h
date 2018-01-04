/**
 * @file save.h
 * @brief Contains function declarations of the save module.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _SAVE_H_
#define _SAVE_H_

#ifdef SAVE_EXPORTS
#define SAVE_API __declspec(dllexport)
#else
#define SAVE_API __declspec(dllimport)
#endif

/**
 * @brief Clears the file if it exists, creates it if not
 * @param pcFilename The file to reset
 * @author Paul Meffle
 * @date 04.01.2018
 */
void SAVE_API resetFile(const char * const pcFilename);

/**
 * @brief Appends the solution to a file
 * @param pcFilename The file to append to
 * @param ppiBoard The array containing the solution
 * @param iSize The size of the array
 * @param iSolutionCount The number of the current solution
 * @return 1 if saving successful, 0 otherwise
 * @author Paul Meffle
 * @date 04.01.2018
 */
int SAVE_API appendToFile(const char * const pcFilename, const int ** const ppiBoard, const int iSize, const int iSolutionCount);

#endif // _SAVE_H_

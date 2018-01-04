#ifndef _PRINT_H_
#define _PRINT_H_

void print(const struct nQueens * const psnQueens);
void printInputScreen(const char *pcMessage, const struct nQueens * const psnQueens);
void printBoard(int ** const ppiBoard, const int iN);
void printSolutionCount(const int iSolutionCount);

#endif // _PRINT_H_

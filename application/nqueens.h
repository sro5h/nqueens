#ifndef _NQUEENS_H_
#define _NQUEENS_H_

enum AppMode
{
        Step,
        Continuous,
};

enum SaveMode
{
        SaveOn,
        SaveOff,
};

struct nQueens
{
        int **ppiBoard;
        int iSize;

        enum AppMode eAppMode;
        enum SaveMode eSaveMode;
        int iShouldClose;
        int iShouldSolve;

        int iSolutionCount;
};

void init(struct nQueens * const psnQueens);
void resetBoard(int ** const ppiBoard, const int iSize);

#endif // _NQUEENS_H_

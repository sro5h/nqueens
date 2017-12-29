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
        int** ppiBoard;
        int iSize;

        AppMode eAppMode;
        SaveMode eSaveMode;

        int iSolutionCount;
};

#endif // _NQUEENS_H_

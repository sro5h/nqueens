#ifndef _NQUEENS_H_
#define _NQUEENS_H_

#include <time.h>

#define DEFAULT_BOARD_SIZE 4
#define DEFAULT_FILENAME   "default.txt"

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

struct AppTime
{
        clock_t lLastTimeStamp;
        double dRuntime;
};

struct nQueens
{
        int **ppiBoard;
        int iSize;
        char acFilename[64];

        enum AppMode eAppMode;
        enum SaveMode eSaveMode;
        int iShouldClose;
        int iShouldSolve;

        struct AppTime sAppTime;

        int iSolutionCount;
};

void init(struct nQueens * const psnQueens);
void resetBoard(int ** const ppiBoard, const int iSize);

#endif // _NQUEENS_H_

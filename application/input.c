#include <conio.h>
#include "input.h"

#define KEY_STOP 1

void awaitInput(struct nQueens * const pnQueens)
{
        char cKey = _getch();

        switch (cKey)
        {
        case 'e':
                pnQueens->iShouldClose = 1;
                break;

        case 's':
                pnQueens->iShouldClose = 1;
                break;

        case 'a':
                pnQueens->eSaveMode = pnQueens->eSaveMode == SaveOn ? SaveOff : SaveOn;
                break;

        case 'm':
                pnQueens->eAppMode = pnQueens->eAppMode == Step ? Continuous : Step;
                break;
        }
}

int checkForExit(struct nQueens * const pnQueens)
{
        if (_kbhit())
        {
                char cKey = _getch();

                switch (cKey)
                {
                case 'e':
                        pnQueens->iShouldClose = 1;
                        return KEY_STOP;

                case 's':
                        return KEY_STOP;
                }
        }

        return 0;
}
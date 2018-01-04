/**
 * @file runtime.c
 * @brief Handles measuring the app runtime
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include "runtime.h"
#include "nqueens.h"

void appendElapsed(struct AppTime * const psAppTime)
{
        clock_t lOldTimeStamp = psAppTime->lLastTimeStamp;
        psAppTime->lLastTimeStamp = clock();

        psAppTime->dRuntime += (double) (psAppTime->lLastTimeStamp - lOldTimeStamp) / CLOCKS_PER_SEC;
}

void discardElapsed(struct AppTime * const psAppTime)
{
        psAppTime->lLastTimeStamp = clock();
}

void resetTime(struct AppTime * const psAppTime)
{
        psAppTime->lLastTimeStamp = clock();
        psAppTime->dRuntime = 0.0;
}

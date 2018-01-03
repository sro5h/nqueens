#include <stdio.h>
#include "save.h"

int appendToFile(const char * const pcFilename, const int ** const ppiBoard, const int iSize)
{
        FILE *pFile;
        char acBuffer[256];

        pFile = fopen(pcFilename, "a");

        if (!pFile) {
                return 0;
        }

        fprintf(pFile, "Hello file!");

        fclose(pFile);

        return 1;
}
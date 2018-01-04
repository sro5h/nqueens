#ifndef _SAVE_H_
#define _SAVE_H

#ifdef SAVE_EXPORTS
#define SAVE_API __declspec(dllexport)
#else
#define SAVE_API __declspec(dllimport)
#endif

void SAVE_API resetFile(const char * const pcFilename);
int SAVE_API appendToFile(const char * const pcFilename, const int ** const ppiBoard, const int iSize, const int iSolutionCount);

#endif // _SAVE_H_
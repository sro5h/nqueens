#ifndef _SAVE_H_
#define _SAVE_H

#ifdef SAVE_EXPORTS
#define SAVE_API __declspec(dllexport)
#else
#define SAVE_API __declspec(dllimport)
#endif

void SAVE_API writeToFile(const int ** const ppiBoard, const int iSize);

#endif // _SAVE_H_
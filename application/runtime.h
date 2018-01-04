#ifndef _RUNTIME_H_
#define _RUNTIME_H_

void appendElapsed(struct AppTime * const psAppTime);
void discardElapsed(struct AppTime * const psAppTime);
void resetTime(struct AppTime * const psAppTime);

#endif // !_RUNTIME_H_

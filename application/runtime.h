/**
 * @file runtime.h
 * @brief Contains function declarations of the runtime module.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

/**
 * @brief Add the measured time since the last call to clock to dRuntime
 * @param psAppTime The struct to store the measurement data in
 * @author Paul Meffle
 * @date 04.01.2018
 */
void appendElapsed(struct AppTime * const psAppTime);

/**
 * @brief Discards the measured time since the last call to clock
 * @param psAppTime The struct to store the measurement data in
 * @author Paul Meffle
 * @date 04.01.2018
 */
void discardElapsed(struct AppTime * const psAppTime);

/**
 * @brief Resets the measurement data
 * @param psAppTime The struct to store the measurement data in
 * @author Paul Meffle
 * @date 04.01.2018
 */
void resetTime(struct AppTime * const psAppTime);

#endif // !_RUNTIME_H_

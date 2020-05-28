#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <ctime>
#include <map>

// print out the steps and errors
void logging(const char *fmt, ...);
std::chrono::milliseconds millisecs_since_epoch();

extern std::map<int, int64_t> ptsMap;  // record PTS values during decode. Add to Alarm files in postprocessing.

#endif // UTILS_H
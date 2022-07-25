#include <Windows.h>
#include <stdint.h>
#include "../include/benchmark.h"

int gettimeofday(timeval * tp) {
    static const uint64_t EPOCH = ((uint64_t) 116444736000000000ULL);

    SYSTEMTIME system_time;
    FILETIME file_time;
    uint64_t time;

    GetSystemTime(&system_time);
    SystemTimeToFileTime(&system_time, &file_time);
    time = ((uint64_t)file_time.dwLowDateTime);
    time += ((uint64_t)file_time.dwHighDateTime) << 32;

    tp->tv_sec = (long)((time - EPOCH) / 10000000L);
    tp->tv_usec = (long)(system_time.wMilliseconds * 1000);
    return 0;
}

timeval timersub(const timeval a, const timeval b) {
    timeval result;

    if (a.tv_sec > b.tv_sec)
    {
        if (a.tv_usec >= b.tv_usec)
        {
            result.tv_sec = a.tv_sec - b.tv_sec;
            result.tv_usec = a.tv_usec - b.tv_usec;
        }
        else
        {
            result.tv_sec = a.tv_sec - b.tv_sec - 1;
            result.tv_usec = 1000000 - b.tv_usec + a.tv_usec;
        }
    }
    else if (a.tv_sec < b.tv_sec)
    {
        if (a.tv_usec > b.tv_usec)
        {
            result.tv_sec = b.tv_sec - a.tv_sec - 1;
            result.tv_usec = 1000000 - a.tv_usec + b.tv_usec;
        }
        else
        {
            result.tv_sec = b.tv_sec - a.tv_sec;
            result.tv_usec = b.tv_usec - a.tv_usec;
        }
    }
    else
    {
        result.tv_sec = 0;
        result.tv_usec = a.tv_usec - b.tv_usec;
    }

    return result;
}

long int millisec(timeval t) {
  return t.tv_sec * 1000 + t.tv_usec / 1000; 
}

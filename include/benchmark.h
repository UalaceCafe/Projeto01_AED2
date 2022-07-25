#ifndef BENCHMARK_H

#define BENCHMARK_H

typedef struct {
    long tv_sec;
    long tv_usec;
} timeval;

int gettimeofday(timeval * tp);
timeval timersub(const timeval a, const timeval b);
long int millisec(timeval t);

#endif

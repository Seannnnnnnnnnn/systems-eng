/* Profiles the cost of a systems calls */
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

const int NUM_ITERS = 1000000;


int main(int argc, char* argv [])
{
    struct timeval start, end;
    
    gettimeofday(&start, NULL);

    for (int i = 0; i < NUM_ITERS; i++)
    {
        getpid();  // system call
    }
    gettimeofday(&end, NULL);

    long long elapsed_us = (end.tv_sec - start.tv_sec) * NUM_ITERS + (end.tv_usec - start.tv_usec);
    double avg_time_per_call = (double)elapsed_us / NUM_ITERS;

    printf("Total time for %d calls: %lld us\n", NUM_ITERS, elapsed_us);
    printf("Average time per call: %.4f us\n", avg_time_per_call);

    return 0;
}
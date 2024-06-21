#include <stdlib.h>
#include <stdio.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

int ScheduleJobs(const job* jobs, size_t j_size) {
    size_t i = 0,pos=0;
    int app = 0, appbest=0, ret = 0,t=0;
    int* presi = calloc(j_size, sizeof(int));
    while (i < j_size) {
        for (size_t c = 0; c < j_size; c++) {
            app = jobs[c].profit / jobs[c].duration;
            if (app == appbest && presi[c]==0) {
                if (jobs[c].duration < jobs[pos].duration) {
                    appbest = app;
                    pos = c;
                }
            }
            else if (app > appbest && presi[c]==0) {
                    appbest = app;
                    pos = c;
            }

        }
        if (t + jobs[pos].duration <= jobs[pos].deadline) {
            t = t + jobs[pos].duration;
            printf("%ld ", pos);
            ret = ret + jobs[pos].profit;
        }
        appbest = 0;
        presi[pos] = 1;
        i++;
    }
    return ret;
}
//int main(void) {
//    job* jobs = calloc(3, sizeof(jobs));
//    jobs[0].duration = 2;
//    jobs[0].profit = 80;
//    jobs[0].deadline = 4;
//    jobs[1].duration = 5;
//    jobs[1].profit = 100;
//    jobs[1].deadline = 6;
//    jobs[2].duration = 1;
//    jobs[2].profit = 30;
//    jobs[2].deadline = 3;
//    printf("Totale : %d", ScheduleJobs(jobs, 3));
//}
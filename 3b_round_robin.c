#include <stdio.h>

typedef struct {
    int id, at, bt, rt, ct, tat, wt;
} Process;

void calculateTimes(Process p[], int n, int q) {
    int current_time = 0, completed = 0;
    float total_tat = 0, total_wt = 0;
printf("the gantt chart\n");
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].rt > 0 && p[i].at <= current_time) {
                if (p[i].rt > q) {
                    current_time += q;
                    p[i].rt -= q;
                    printf("P%d\t",p[i].id);
                } else {
                  printf("P%d\t",p[i].id);
                    current_time += p[i].rt;
                    p[i].ct = current_time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    total_tat += p[i].tat;
                    total_wt += p[i].wt;
                    p[i].rt = 0;
                    completed++;
                }
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id,
               p[i].at, p[i].bt,
               p[i].ct, p[i].tat,
               p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

int main() {
    int n, q;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];
    printf("Enter arrival and burst times:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d Arrival time: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("P%d Burst time: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; // Remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);

    calculateTimes(p, n, q);

    return 0;
}


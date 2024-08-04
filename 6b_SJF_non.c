#include <stdio.h>

typedef struct {
    int id;
    int at; // Arrival Time
    int bt; // Burst Time
    int ct; // Completion Time
    int tat; // Turnaround Time
    int wt; // Waiting Time
    int completed; // Completion flag
} Process; // Process

void calculateTimes(Process p[], int n) {
    int time = 0, completed = 0;
    int total_tat = 0, total_wt = 0;
   printf("The Gantt chart\n");
    while (completed != n) {
        int min_index = -1;
        int min_bt = 100000; // A large number

      
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && !p[i].completed) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            
            time++;
        } else {
           printf("P%d ", p[min_index].id);
             time += p[min_index].bt;
            p[min_index].ct = time;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;

            total_tat += p[min_index].tat;
            total_wt += p[min_index].wt;
            p[min_index].completed = 1;
            completed++;
        }
    }

    // Print results
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id,
               p[i].at, p[i].bt, p[i].ct, p[i].tat,
               p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process P%d:\n", p[i].id);
        printf("Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Burst time: ");
        scanf("%d", &p[i].bt);
        p[i].completed = 0;
    }

    calculateTimes(p, n);

    return 0;
}

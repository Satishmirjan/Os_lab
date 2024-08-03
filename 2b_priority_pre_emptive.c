#include <stdio.h>
#include <limits.h>


typedef struct {
    int id;
    int at;  // Arrival Time
    int bt;  // Burst Time
    int pri; // Priority
    int rt;  // Remaining Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
} Process;


void calculateTimes(Process p[], int n) {
    int curr_time = 0, completed = 0;
    int total_tat = 0, total_wt = 0;
    int prev_high_idx = -1;

    printf("The Gantt chart\n");

    while (completed != n) {
        int high_idx = -1;
        int high_pri = INT_MAX;

        // Find the process with the highest priority that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= curr_time && p[i].rt > 0) {
                if (p[i].pri < high_pri || (p[i].pri == high_pri && p[i].at < p[high_idx].at)) {
                    high_pri = p[i].pri;
                    high_idx = i;
                }
            }
        }

       //here iam checking whether process changed or not , if it changed then only i print it
        // if (prev_high_idx != high_idx && high_idx != -1) {
        //     printf("P%d ", p[high_idx].id);
        //     prev_high_idx = high_idx;
        // }
        
         

        // no process is arrived 
        if (high_idx == -1) {
            curr_time++;
            continue;
        }
        printf("P%d ", p[high_idx].id);

       
        p[high_idx].rt--;
        curr_time++;

        
        if (p[high_idx].rt == 0) {
            completed++;
            p[high_idx].ct = curr_time;
            p[high_idx].tat = p[high_idx].ct - p[high_idx].at;
            p[high_idx].wt = p[high_idx].tat - p[high_idx].bt;
            total_tat += p[high_idx].tat;
            total_wt += p[high_idx].wt;
        }
    }

    // Print results
    printf("\n\nProc\tArrival\tBurst\tPriority\tComp\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,
               p[i].at, p[i].bt,
               p[i].pri, p[i].ct,
               p[i].tat, p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter details of Process P%d:\n", p[i].id);
        printf("Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Burst time: ");
        scanf("%d", &p[i].bt);
        printf("Priority : ");
        scanf("%d", &p[i].pri);
        p[i].rt = p[i].bt; 
    }

    calculateTimes(p, n);

    return 0;
}

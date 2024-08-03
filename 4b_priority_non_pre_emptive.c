#include <stdio.h>
#include <limits.h>
//(lower number indicates higher priority)
typedef struct
{
  int id;
  int at;  // Arrival Time
  int bt;  // Burst Time
  int pri; // Priority
  int ct;  // Completion Time
  int tat; // Turnaround Time
  int wt;  // Waiting Time
} Process;
void calculateTimes(Process p[], int n)
{
  int curr_time = 0, completed = 0;
  int total_tat = 0, total_wt = 0;
    printf("the gantt chart\n");

  while (completed != n)
  {
    int high_pri_idx = -1;
    int high_pri = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      if (p[i].at <= curr_time && p[i].ct == 0)
      {
        if (p[i].pri < high_pri)
        {
          high_pri = p[i].pri;
          high_pri_idx = i;
        }
      }
    } printf("P%d\t",p[high_pri_idx].id);

    // no process is arrived at that time
    if (high_pri_idx == -1)
    {
      curr_time++;
      continue;
    }

    curr_time += p[high_pri_idx].bt;
    p[high_pri_idx].ct = curr_time;
    p[high_pri_idx].tat = curr_time - p[high_pri_idx].at;
    p[high_pri_idx].wt = p[high_pri_idx].tat - p[high_pri_idx].bt;

    total_tat += p[high_pri_idx].tat;
    total_wt += p[high_pri_idx].wt;
    completed++;
  }

  printf("\nProc\tArrival\tBurst\tPriority\tComp\tTurnaround\tWaiting\n");
  for (int i = 0; i < n; i++)
  {
    printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,
           p[i].at, p[i].bt,
           p[i].pri, p[i].ct,
           p[i].tat, p[i].wt);
  }
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
  printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main()
{
  int n;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process p[n];
 
  for (int i = 0; i < n; i++)
  {printf("Enter details of Process P%d:\n", p[i].id);
    p[i].id = i + 1;
    printf("Process P%d:\n", p[i].id);
    printf("Arrival time: ");
    scanf("%d", &p[i].at);
    printf("Burst time: ");
    scanf("%d", &p[i].bt);
    printf("Priority : ");
    scanf("%d", &p[i].pri);
    p[i].ct = 0; // Iam using completion time
  }

  calculateTimes(p, n);

  return 0;
}

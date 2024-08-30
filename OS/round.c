#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;
    int at;
    int wt;
    int tat;
    int bt_print;
    int bt;
    int ct;
    int scheduled;
} p[20], temp;

int n;
int tq;
float total_wt = 0, total_tat = 0;
float avg_wt, avg_tat;
int time_units = 0;
int tail = -1;
int ready_queue[20];

void push(int idx) {
    ready_queue[++tail] = idx;
}

int pop() {
    int idx;
    int i;
    if (tail == -1) {
        return -1;
    }
    idx = ready_queue[0];
    for (i = 1; i <= tail; ++i) {
        ready_queue[i - 1] = ready_queue[i];
    }
    --tail;
    return idx;
}

void display_item(int i) {
   //rintf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].pid, p[i].at, p[i].bt_print, p[i].ct, p[i].tat, p[i].wt);
printf("%d\t\t\t",p[i].pid);
printf("%d\t\t\t",p[i].at);
printf("%d\t\t\t",p[i].bt_print);
printf("%d\t\t\t\t",p[i].ct);
printf("%d\t\t\t",p[i].tat);
printf("%d\t\t",p[i].wt);
printf("\n");
}

void display() {
    int i;
    printf("Time Quantum: %d\n", tq);
    printf("Process ID\t\tArrival Time\t\tBurst Time\t\tCompletion Time \t\tTurnaround Time\t\tWaiting Time\n");
    for (i = 0; i < n; i++)
        display_item(i);
    avg_wt = total_wt / n;
    avg_tat = total_tat / n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
}

void swap(int i, int j) {
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

void pid_sort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].pid > p[j + 1].pid) {
                swap(j, j + 1);
            }
        }
    }
}

void at_sort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                swap(j, j + 1);
            }
        }
    }
}

int execute(int i) {
    int time = 0;
    if (p[i].bt > tq) {
        time = tq;
        time_units += time;
    } else {
        time = p[i].bt;
        time_units += time;
        p[i].ct = time_units;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt_print;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }
    p[i].bt -= time;
    return time;
}

void add_newly_arrived_tasks(int last_executed) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].bt == 0) {
            continue;
        }
        if (p[i].scheduled == 1) {
            continue;
        }
        if (p[i].at <= time_units) {
            push(i);
            p[i].scheduled = 1;
        }
    }
}

void rr() {
    int current_task;
    int time;
    at_sort();
    push(0);
    p[0].scheduled = 1;
    while (1) {
        current_task = pop();
        if (current_task == -1) {
            break;
        }
        time = execute(current_task);
        add_newly_arrived_tasks(current_task);
        if (p[current_task].bt > 0) {
            push(current_task);
        }
    }
    pid_sort();
    printf("\nRR: \n");
    display();
}

int main() {
    int i;
    printf("Kindly enter the number of processes: ");
    scanf("%d", &n);
    printf("Kindly enter the time quantum: ");
    scanf("%d", &tq);
    printf("\n");
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].bt_print);
        p[i].bt = p[i].bt_print;
        p[i].scheduled = 0;
    }
    rr();
    return 0;
}
	


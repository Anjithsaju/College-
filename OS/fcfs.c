#include<stdio.h>
#include<stdlib.h>
struct process
{
char pid[5];
int at;
int wt;
int tat;
int bt;
int ct;
}p[20],temp;
int n;
void asort()
{

for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{


temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}

}
void fcfs()
{
float sum1=0,sum2=0;
asort();
p[0].ct=p[0].at+p[0].bt;
p[0].tat=p[0].ct-p[0].at;
p[0].wt=p[0].tat-p[0].wt;
p[0].wt=p[0].tat-p[0].bt;
sum1=sum1+p[0].tat;
sum2=sum2+p[0].wt;
//printf("this:%d",p[0].ct);
for(int i=1;i<n;i++)
{
p[i].ct=p[i-1].ct +p[i].bt;

p[i].tat=p[i].ct-p[i].at;
sum1=sum1+p[i].tat;
p[i].wt=p[i].tat-p[i].bt;
sum2=sum2+p[i].wt;
}
printf("FCFS:\n");
printf("Proccess id \tArrival time \tBurst time \tcompletion time \tTurn around time \tWaiting time\n");
for(int i=0;i<n;i++)
{
printf("%s\t\t",p[i].pid);
printf("%d\t\t",p[i].at);
printf("%d\t\t",p[i].bt);
printf("%d\t\t\t",p[i].ct);
printf("%d\t\t\t",p[i].tat);
printf("%d\t\t",p[i].wt);
printf("\n");
}
printf("average turn around time:%f\n",(sum1/2));
printf("average waiting time:%f\n",(sum2/2));
}
void main()
{
printf("enter the number of proccess");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("Enter pid of proccess(%d) :",(i+1));
scanf("%s",p[i].pid);
printf("Enter arrival time of proccess(%d) :",(i+1));
scanf("%d",&p[i].at);
printf("Enter burst time of proccess(%d) :",(i+1));
scanf("%d",&p[i].bt);
}
fcfs();
}


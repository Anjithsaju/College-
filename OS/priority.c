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
int pr;
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

void btsort(struct process p[20],int i,int n,int ict)
{
for(int a=i+1;a<n;a++)
{
for(int b=a;b<n;b++)
{
if((p[a].at<=ict)&&(p[b].at<=ict))
{
if(p[a].pr>p[b].pr)
{
temp=p[a];
p[a]=p[b];
p[b]=temp;
}

}
}
}

}
void priority()
{
float sum1=0,sum2=0;
asort();
int ict=p[0].at;
//p[0].ct=p[0].at+p[0].bt;
//p[0].tat=p[0].ct-p[0].at;
/*p[0].wt=p[0].tat-p[0].wt;
p[0].wt=p[0].tat-p[0].bt;
sum1=sum1+p[0].tat;
sum2=sum2+p[0].wt;*/
//printf("this:%d",p[0].ct);
for(int i=0;i<n;i++)
{
if(ict<p[i].at)
p[i].ct=p[i].at+p[i].bt;
else
p[i].ct=ict +p[i].bt;
ict=p[i].ct;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
sum1=sum1+p[i].tat;

sum2=sum2+p[i].wt;
btsort(p,i,n,ict);
}
printf("FCFS:\n");
printf("Priority \tProccess id \tArrival time \tBurst time \tcompletion time \tTurn around time \tWaiting time\n");
for(int i=0;i<n;i++)
{
printf("%d\t\t",p[i].pr);
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
printf("Enter priority  of proccess(%d) :",(i+1));
scanf("%d",&p[i].pr);
}
priority();
}


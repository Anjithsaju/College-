#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
pid_t pid=fork();
if(pid==0)
{
printf("Hello\n");
exit(EXIT_SUCCESS);
}
else if(pid>0)
{
printf("Main Task \n");
}
else
{
printf("Unable to create");
}
return EXIT_SUCCESS;
}


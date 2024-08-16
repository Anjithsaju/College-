#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main()
{
struct stat sfile;
stat("hello.c",& sfile);
printf("st_size=%ld \n",sfile.st_size);
}

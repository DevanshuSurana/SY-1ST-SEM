#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t num_pid;
void main()
{
  num_pid=fork();
if(num_pid=0)
{
	printf("errorin fork excution");
}
  else
if(num_pid=0)
{
	printf("this a chuild process");
}
else
{
	printf("this is the parent id %d \n", getpid());
	wait(NULL);
}
exit(0);
}

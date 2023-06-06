#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){

pid_t pid;
pid = fork();
if(pid ==-1)

printf("Process does not exist") ; 
else if(pid==0)
{
printf("This is a child process with id %ld \n" , (long)getpid());
printf("This is a parent process with if %ld \n" , (long)getppid());
}
else
{printf("Back to main program with PID %ld \n" , (long)getpid());
printf("Started child PID is  %ld \n" , (long)pid);
}

printf("Sleeping for 3 secs\n");
sleep(3);

 return 0;
}

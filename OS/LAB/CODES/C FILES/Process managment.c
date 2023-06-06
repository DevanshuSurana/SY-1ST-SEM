#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h> 
pid_t pid;
int fd[2]; int main(){ int n;
char s[50],c[50];
printf("Enter message to be read: \n");
scanf("%s",&c);
n = pipe(fd);
if(n == 0){
printf("Pipe created successfully");
 pid = fork(); if(pid == 0){

printf("Executing child process %d\n",getpid()); close(fd[1]);
read(fd[0],s,50);
printf("The message read from parent is %s\n",s);
} else{
printf("Executing Parent process %d\n", getpid()); close(fd[0]);
write(fd[1],c,50);
}
}
else if(n < 0){
printf("Failure\n"); }
else{
printf("Hello!");
}
return 0; }
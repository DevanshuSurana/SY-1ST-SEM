#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  fork();
	printf("hi \n ");
  fork();
	printf("hello world \n ");
  return 0;
}

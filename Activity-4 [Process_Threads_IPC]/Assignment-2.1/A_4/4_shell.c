/*4. Design a mini shell of your own as follows
   * take command name as input from user (string format)...
   * launch the command in the child process using execl/execlp
   * parent will wait for completion of child and print exit status*/


#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	
	printf("Enter the command: \n");
	char s[100];
	scanf(" %[^\n]s\n",s);
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{ 
    	execl("/bin/sh","sh","-c",s,NULL) ; 
	}
	else	
	{
		waitpid(ret, &returni, 0); 
	}
	exit(0);
}


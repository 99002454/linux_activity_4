/*15. Design a mini shell of your own as follows
   * take command name as input from user (string format)...
   * launch the command in the child process using execl/execlp
   * parent will wait for completion of child and print exit status
   Extention of mini shell
   */
/*sudo apt-get install libreadline-dev install readline*/

#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main(int argc,char *argv[])
{
int i;int ret,returni;
	if(argc==1)
	{
	printf("no Commands to execute\n");return 1;
	}
	size_t size=1;
	for(i=1;i<argc;i++)
	size+=strlen(argv[i])+1;
	char *s=malloc(size);
	for(i=1;i<argc;i++)
	{
	strcat(s,argv[i]);
	strcat(s," ");
	}
	//printf("Enter the command: \n");
	//int i;
	//scanf(" %[^\n]s\n",s);
	ret=fork();
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


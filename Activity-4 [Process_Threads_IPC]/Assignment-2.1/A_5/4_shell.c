/*5. Write a program to compile & link any c/c++ program within child process by launching gcc using execl/execlp.*/


#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	ret=fork();
	char *s;
	char *ss;
	s="s.out"; 
	
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{ 
    	execl("/bin/g++","g++","-c","samp.cpp",NULL) ; 
	}
	else	
	{
	waitpid(ret, &returni, 0); 
	execl("/bin/g++","g++","samp.o","-o",s,NULL); 
	}
	exit(0);
}


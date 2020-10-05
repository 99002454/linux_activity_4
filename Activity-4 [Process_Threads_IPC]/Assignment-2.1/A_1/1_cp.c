/*1. Write a program to copy one file contents to other using open,read,write,close system 
   calls (like cp command, which takes source, destination files as cmd line args). 
   */
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int fd1,nbytes1,d,nbytes2,fd2;
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_WRONLY|O_CREAT, 0666);
	if(fd1<0 && fd2<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes1=read(fd1,buf,maxlen);
	nbytes2=write(fd2,buf,nbytes1);
	if(nbytes1<0 && nbytes2<0)
	{
		perror("read");
		exit(2);
	}
	close(fd1);
	close(fd2);
	return 0;	
}
		






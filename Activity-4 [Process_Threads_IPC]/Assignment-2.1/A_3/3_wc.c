/*Write a program to count no.of lines, words, characters in given file (like wc command)
*/
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int fd1,nbytes1,d,nbytes2,fd2;
	int word=0,line=0,i;	
	int inword=0;
	fd1=open(argv[1],O_RDONLY);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes1=read(fd1,buf,maxlen);
	

	//nbytes2=write(fd2,buf,nbytes1);
	if(nbytes1<0)
	{
		perror("read");
		exit(2);
	}
	else
	{
	i=0;
	while(i!=nbytes1)
	{ 
	 if(buf[i]==' '|| buf[i]=='\t' ||buf[i]=='\n' ||buf[i]=='\0')
	 {

	 if(inword)
	 {
	 inword=0;
	 word++;
	 }
	 
	 if(buf[i]=='\n'||buf[i]=='\0')
	 line++;
	 }
	 else
	 {
	 inword=1;
	 }
	 i++;
	}
	}
	printf("word :%d line :%d char:%d",word,line,nbytes1);
	//write(1,buf,nbytes1);
	close(fd1);
	return 0;	
}
		


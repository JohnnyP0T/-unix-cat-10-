#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#define BUFSIZE 512
int main(int argc,char *argv[]){
	int fil;
	char buffer[BUFSIZE];
	off_t filesize;
	ssize_t nread;
	if (argc != 2){
		printf("Need 1 argument for open\n");
		exit(1);
	}
	if((fil = open(argv[1],O_RDONLY)) == -1){
		printf("Cannot open file %s\n",argv[1]);
		exit(1);
	}
	if((nread = read(fil,buffer,BUFSIZE)) == -1){
		printf("Cannot read file %s\n",argv[1]);
		exit(1);
	}
	if((filesize = lseek(fil,(off_t)0,SEEK_END)) == 0){
		printf("File %s",argv[1]);
		printf(" is empty\n");
		exit(1);
	}
	printf("%s", buffer);
	int t = close(fil);
}

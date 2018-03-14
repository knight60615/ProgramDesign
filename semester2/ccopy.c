#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define Maxsize 1000000
int main(int argc, char *argv[])
{
		int fd1,fd2,i;
		char buf[Maxsize];
		if(argc==2){
				fd1=open(argv[1],O_RDWR,0);
				while(read(STDIN_FILENO,buf,Maxsize)>0){
						write(fd1,buf,strlen(buf));
				}
		}
		else {
				fd2=open(argv[argc-1],O_RDWR,0);
				for(i=1;i<argc-1;i++){
					fd1=open(argv[i],O_RDONLY,0);
					while(read(fd1,buf,Maxsize)>0){
					write(fd2,buf,strlen(buf));
					}
				}
		}

		return 0;
}

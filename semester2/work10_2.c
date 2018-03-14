#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define Maxsize 1000000
int main(int argc, char *argv[])
{
		int fd1,fd2,i=0,j=0,k=0,start,Size;
		char filename[50],*ptr,*lptr,buf[Maxsize],record[Maxsize],value[Maxsize],key[100],offset[Maxsize],size[Maxsize];
		fd1=open(argv[2],O_RDONLY,0);
		if(fd1==-1){				
				printf("open failed\n");
				return 0;
		}
/*		for(ptr=argv[2];*ptr!='.';ptr++){
				filename[i++]=*ptr;
		}*/
		if(!(ptr=strstr(argv[2],".idx"))){
printf("error\n");
return 0;
		}
		*ptr='\0';
	/*	while(ptr<lptr)
				 filename[i++]=*ptr++;
		filename[i]='\0';*/
		strcpy(filename,argv[2]);
//		printf("%s\n",filename);
		fd2=open(filename,O_RDONLY,0);
		if(fd2==-1){				
				printf("open failed\n");
				return 0;
		}
		while((i=read(fd1,buf,Maxsize))>0){
				ptr=buf;
				lptr=buf+i;
				while(ptr<lptr){
						while(*ptr!='\t'&&ptr<lptr){		//把key存出來
								key[j++]=*ptr++;
						}
						if(*ptr=='\t'){
								key[j]='\0';
								if(strcmp(argv[1],key)==0){		//比對成功/
										ptr++;
										for(;*ptr!='\t';ptr++){		//把offset存出來
												offset[k++]=*ptr;
										}
										offset[k]='\0';
										ptr++;
										k=0;
										for(;*ptr!='\n';ptr++){		//把size存出來
												size[k++]=*ptr;
										}
										ptr++;
										size[k]='\0';
										start=atoi(offset);
										Size=atoi(size);
										lseek(fd2,start,SEEK_SET);		//跳到start的位置
										read(fd2,record,Size);			//從start讀入size位存在record裡
										for(k=0;record[k]!='\t';k++)
										{}								//略過key
										i=0;
										k++;
										for(;record[k]!='\n';k++){
												value[i++]=record[k];			//把value存出來
										}
										value[k]='\0';
										printf("%s\n",value);
										close(fd1);
										close(fd2);
										return 0;
								}
								else{							//比對失敗
									while(*ptr!='\t'){			//略過offset
											ptr++;
									}
									while(*ptr!='\n'){			//略過value
											ptr++;
									}
								ptr++;
								j=0;
								}

						}
				}

		}

		printf("NOT FOUND\n");
		close(fd1);
		close(fd2);
		return 0;
}

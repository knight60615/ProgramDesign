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
						while(*ptr!='\t'&&ptr<lptr){		//��key�s�X��
								key[j++]=*ptr++;
						}
						if(*ptr=='\t'){
								key[j]='\0';
								if(strcmp(argv[1],key)==0){		//��令�\/
										ptr++;
										for(;*ptr!='\t';ptr++){		//��offset�s�X��
												offset[k++]=*ptr;
										}
										offset[k]='\0';
										ptr++;
										k=0;
										for(;*ptr!='\n';ptr++){		//��size�s�X��
												size[k++]=*ptr;
										}
										ptr++;
										size[k]='\0';
										start=atoi(offset);
										Size=atoi(size);
										lseek(fd2,start,SEEK_SET);		//����start����m
										read(fd2,record,Size);			//�qstartŪ�Jsize��s�brecord��
										for(k=0;record[k]!='\t';k++)
										{}								//���Lkey
										i=0;
										k++;
										for(;record[k]!='\n';k++){
												value[i++]=record[k];			//��value�s�X��
										}
										value[k]='\0';
										printf("%s\n",value);
										close(fd1);
										close(fd2);
										return 0;
								}
								else{							//��異��
									while(*ptr!='\t'){			//���Loffset
											ptr++;
									}
									while(*ptr!='\n'){			//���Lvalue
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

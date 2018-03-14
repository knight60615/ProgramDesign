#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define MAXLEN 100000

int main(int argc, char *argv[])
{
	int idx,data,i;
	int size,offset=-1;
	char *filename,*key,*buf,*ptr;
	if (argc!=3)
	{   printf("��J���~\n");
		return 1;   }

	
	if((idx=open(argv[2],O_RDONLY))==-1)
	{   printf("�L�k�}���ɮ�:%s\n",argv[2]);
		return 1;   }

	
	if (!(ptr=strstr(argv[2],".idx")))
	{	printf("��J���~\n");
		return 1;	}
	*ptr='\0';

	filename=(char *)malloc(strlen(argv[2])+1);
	strcpy(filename,argv[2]);
	
	
	
	
	
	
	//	filename=strtok(filename,".");
	key=(char *)malloc(strlen(argv[1])+1);
	strcpy(key,argv[1]);


	if((data=open(filename, O_RDONLY))==-1)
	{   printf("�L�k�}���ɮ�:%s\n",filename);
		return 1;   }

	size=lseek(idx,0,SEEK_END);   //  ���ɮפj�p
	buf=(char *)malloc(size+1);     //  �n�Ŷ� �@���Y��
	if(buf==NULL)
	{   printf("malloc����\n");
		return 1;   }
	lseek(idx,0,SEEK_SET);
	read(idx,buf,size);

	buf=strtok(buf,"\t\n");     //  ��strtok���r

	i=0;
	while(buf!=NULL)
	{
		if(strcmp(buf,key)==0)
		{   offset=atoi(strtok(NULL,"\t\n"));
			size=atoi(strtok(NULL,"\t\n"));     }
		buf=strtok(NULL,"\t\n");    //  ���U�@�Ӧr
	}
	close(idx);

	if(offset==-1)
		fprintf(stderr,"Not Found!!\n");
	else
	{   lseek(data,offset,SEEK_SET);
		buf=(char *)malloc(size+1);
		read(data,buf,size);
		buf = strtok(buf,"\t\n");
		buf = strtok(NULL,"\t\n");
		printf("%s\n",buf);
	}
	close(data);
	return 0;
}

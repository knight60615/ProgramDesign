#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int input,output;
    char *filename,*loc;
    char *buf,outbuf[10000];
    int i,total,size;
    if (argc!=2)
    {   printf("��J���~\n");
        return 1;   }

    if ((input=open(argv[1],O_RDONLY))==-1)
    {   printf("�L�k�}���ɮ�:%s\n",argv[1]);
        return 1;   }

	for(i=(strlen(argv[1])-1);i>0;i--)
	{	//	printf("%d\n",i);
		if (argv[1][i]=='/')
		{	loc=argv[1]+i+1;
			break;	}
	}
//	printf("%s\n",loc);
	if (i==0)

	{	filename=(char *)malloc(strlen(argv[1])+4);
		strcpy(filename,argv[1]);	}
	
	
	else if (i<=1)	//	���a��
	{	filename=(char *)malloc(strlen(argv[1])+4);
		strcpy(filename,loc);	}
	else
	{	filename=(char *)malloc(strlen(loc)+4);
		strcpy(filename,loc);	
	    if ((output=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666))==-1)
		    return 1;       //  0666��ܥ�����Ū��g���v��
		size=lseek(input,0,SEEK_END);   //  ���ɮפj�p
		buf=(char *)malloc(size+1);     //  �n�Ŷ� �@���Y��
		lseek(input,0,SEEK_SET);
		read(input,buf,size);

		write(output,buf,strlen(buf)); 
		close(output);
	}
	
	
	

	//	printf("%s",filename);


    


    
	strcat(filename,".idx");
    
    
    if ((output=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666))==-1)
        return 1;       //  0666��ܥ�����Ū��g���v��
    
    
		size=lseek(input,0,SEEK_END);   //  ���ɮפj�p
		buf=(char *)malloc(size+1);     //  �n�Ŷ� �@���Y��
		lseek(input,0,SEEK_SET);
		read(input,buf,size);
   



    if(buf==NULL)
    {   printf("malloc����\n");
        return 1;   }
    lseek(input,0,SEEK_SET);
    read(input,buf,size);
    buf=strtok(buf,"\t\n");     //  ��strtok���r
    i=total=0;
    while(buf!=NULL)
    {
        i++;
        if (i%2)
        {   write(output,buf,strlen(buf));  //  �g�Jkey
            size=strlen(buf)+1; }
        else
        {   size=size+strlen(buf)+1;
            sprintf(outbuf,"\t%u\t%u\n",total,size);
            //  �Ntotal,size�g�J�Ȧs�Ŷ�
            write(output,outbuf,strlen(outbuf));   // �g�J�ɮ�
            total+=size;
            i=0;    }
        buf=strtok(NULL,"\t\n");    //  ���U�@�Ӧr
    }
    close(input);
    close(output);
    return 0;
}

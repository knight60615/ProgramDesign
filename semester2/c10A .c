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
    {   printf("輸入有誤\n");
        return 1;   }

    if ((input=open(argv[1],O_RDONLY))==-1)
    {   printf("無法開啟檔案:%s\n",argv[1]);
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
	
	
	else if (i<=1)	//	本地的
	{	filename=(char *)malloc(strlen(argv[1])+4);
		strcpy(filename,loc);	}
	else
	{	filename=(char *)malloc(strlen(loc)+4);
		strcpy(filename,loc);	
	    if ((output=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666))==-1)
		    return 1;       //  0666表示全部有讀跟寫的權限
		size=lseek(input,0,SEEK_END);   //  算檔案大小
		buf=(char *)malloc(size+1);     //  要空間 一次吃完
		lseek(input,0,SEEK_SET);
		read(input,buf,size);

		write(output,buf,strlen(buf)); 
		close(output);
	}
	
	
	

	//	printf("%s",filename);


    


    
	strcat(filename,".idx");
    
    
    if ((output=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666))==-1)
        return 1;       //  0666表示全部有讀跟寫的權限
    
    
		size=lseek(input,0,SEEK_END);   //  算檔案大小
		buf=(char *)malloc(size+1);     //  要空間 一次吃完
		lseek(input,0,SEEK_SET);
		read(input,buf,size);
   



    if(buf==NULL)
    {   printf("malloc失敗\n");
        return 1;   }
    lseek(input,0,SEEK_SET);
    read(input,buf,size);
    buf=strtok(buf,"\t\n");     //  用strtok切字
    i=total=0;
    while(buf!=NULL)
    {
        i++;
        if (i%2)
        {   write(output,buf,strlen(buf));  //  寫入key
            size=strlen(buf)+1; }
        else
        {   size=size+strlen(buf)+1;
            sprintf(outbuf,"\t%u\t%u\n",total,size);
            //  將total,size寫入暫存空間
            write(output,outbuf,strlen(outbuf));   // 寫入檔案
            total+=size;
            i=0;    }
        buf=strtok(NULL,"\t\n");    //  切下一個字
    }
    close(input);
    close(output);
    return 0;
}

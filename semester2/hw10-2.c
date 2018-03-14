#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define Maxsize 500
int main(int argc,char **argv)
{ FILE *fp;
  int fd1,fd2,i=0,k=0,start,size;
  char buf[Maxsize],Start[Maxsize],Size[Maxsize],Record[Maxsize],Value[Maxsize],name[10],*p,*q;
  if(argc!=3) printf("INPUT ERROR\n");
  if((fd1=open(argv[2],O_RDWR,0))==-1) { printf("NO FILE\n");
                                         return 0;
                                       }
  for(p=argv[2];*p!='.';p++,i++) name[i]=*p;
  name[i]='\0';
  i=0;
  if((fd2=open(name,O_RDWR,0))==-1) { printf("NO FILE\n");
                                      return 0;
                                    }
  fp=fopen(argv[2],"r");
  while(fgets(buf,Maxsize,fp)>0)
   { if((p=strstr(buf,argv[1]))!=NULL)
       { q=p+strlen(argv[1]);
         if(*q=='\t')
          { q++;
            for(;*q!='\t';q++) Start[i++]=*q;
            Start[i]='\0';
            start=atoi(Start);
            q++;
            for(i=0;*q!='\n';q++) Size[i++]=*q;
            Size[i]='\0';
            size=atoi(Size);
            lseek(fd2,start,SEEK_SET);
            read(fd2,Record,size);
            for(i=0;Record[i]!='\t';i++);
            i++;
            for(;Record[i]!='\n';k++,i++) Value[k]=Record[i];
            Value[k]='\0';
            printf("%s\n",Value);
            close(fd1);
            close(fd2);
            return 0;
          }
       }  
    } 
   printf("NOT FOUND\n");
   close(fd1);
   close(fd2);
   return 0;
}

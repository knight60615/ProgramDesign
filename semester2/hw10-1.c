#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define Maxsize 500
void reverse(char *s)
{ int a=0,b=strlen(s)-1;
  char c;
  for(;a<b;a++,b--)
   { c=s[a];
     s[a]=s[b];
     s[b]=c;
   }
}
void itoa(char *s,int x)
{ int i=0,sign;
  if(x==0) s[i++]='0';
  if((sign=x)<0) x=-x;
  while(x>0)
      { s[i++]=x%10+'0';
        x/=10;
      }
  if(sign<0) s[i++]='-';
  s[i]='\0';
  reverse(s);
}
int main(int argc,char **argv)
{ long start,size=0,n=0,k=0,i;
  int fd1,fd2;
  char buf[Maxsize],idx[Maxsize],*p,*q,Start[Maxsize],Size[Maxsize],name[Maxsize];
  if((fd1=open(argv[1],O_RDWR,0))==-1) { printf("NO FILE\n");
                                     return 0;
                                   }
  strcpy(name,argv[1]);
  strcat(name,".idx");
  creat(name,0644);
  fd2=open(name,O_RDWR,0);
  start=lseek(fd1,0,SEEK_SET);
  while((i=read(fd1,buf,Maxsize))>0) 
   { p=buf;
     q=buf+i;    
     while(p<q) 
      { while(idx[k]!='\t'&&*p!='\t'&&p<q)
        { if(n==0) start+=size;
          idx[n++]=*p++;
        }
        if(idx[k]!='\t'&&p<q){ idx[n]=*p++;
                               idx[n+1]='\0';
                               k=n;
                               n++;
                             }  
        while(*p!='\n'&&*p!='\0'&&p<q)
         { p++;
           n++;
	     }
	    n++; 
        if(p<q){ size=n;     
                 itoa(Start,start);
                 itoa(Size,size);
                 strcat(idx,Start);
                 strcat(idx,"\t");
                 strcat(idx,Size);
                 strcat(idx,"\n");
                 n=strlen(idx);
                 write(fd2,idx,n);
                 n=0;
                 k=0;
                 p++;
               }
       }     
    }
 close(fd1);
 close(fd2);
 return 0;
}

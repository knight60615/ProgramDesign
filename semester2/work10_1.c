#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define Maxsize 1000000
void reverse(char*s){
		int a,b;
		char c;
		b=strlen(s)-1;
		for(a=0;a<b;a++){
				c=s[a];
				s[a]=s[b];
				s[b]=c;
				b--;
		}
}
void itoa(char *s,int n){
		int i,sign;
		if((sign=n)<0)		//�p�G�t��
				n=-n;
				i=0;
				do{
						s[i++]=n%10+'0';
				}while((n/=10)>0);
				if(sign<0)		//�p�G�t��
						s[i++]='-';
						s[i]='\0';
						reverse(s);
}

int main(int argc, char *argv[])
{
		int fd1,fd2;
		long i,j=0,start=0,k;
		char buf[Maxsize],name[50],*ptr,*lptr,input[Maxsize],offset[Maxsize],size[Maxsize];
		fd1=open(argv[1],O_RDONLY,0);
		if(fd1==-1){				
				printf("open failed\n");
				return 0;
		}
		strcpy(name,argv[1]);
		strcat(name,".idx");
		creat(name,0644);		//�إ�index��
		fd2=open(name,O_RDWR,0);
		while((i=read(fd1,buf,Maxsize))>0){
				ptr=buf;
				lptr=buf+i;
				while(ptr<lptr){
						while(*ptr!='\t'&&ptr<lptr){		//�J��\t���e,�]�N�Okey
								input[j++]=*ptr++;	
						}
						if(*ptr=='\t'){			//�J��key,��\t�ɤW
								input[j]=*ptr++;
								input[j+1]='\0';
								j++;
						}
						while(*ptr!='\n'&&*ptr!='\0'&&ptr<lptr){		//value���Φs,�O���״N�n
								ptr++;
								j++;
						}
						if(*ptr=='\n'){		//��iinput
							j++;	//\n�S���,��+
							itoa(offset,start);
							itoa(size,j);
							strcat(offset,"\t");
							strcat(offset,size);
							strcat(offset,"\n");
							strcat(input,offset);
							k=strlen(input);
							write(fd2,input,k);
							start+=j;	//�U�@��key���_�l��m
							j=0;
							ptr++;
						}

				}




		}

		return 0;
}

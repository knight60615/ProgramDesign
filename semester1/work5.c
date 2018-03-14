#include<stdio.h>
#include<string.h>
#define OUT 0
#define IN 1
#define Maxword 64
int main()
{
int c,i=0,state,length,num,max=0;
char cword[Maxword]={0},longword[Maxword]={0};
state=OUT;
printf("叫块琿ゅ籔计 , 祘Α盢穦陪ボ程虫籔程计 , 挡叫ctrl+D\n");
while ((c=getchar())!=EOF)
{
		if (c=='\n'||c==' '||c=='\t'){    //虫
            state=OUT;
            cword[i]='\0';                //﹃挡Ю
            length=strlen(cword);         //璸衡﹃
            num=atoi(cword);              //盢计锣传ㄓ
            if(length>strlen(longword)){  //璝﹃>程﹃
            strcpy(longword,cword);}      //р﹃跑Θ程
            if(num>max){                  //璝计>程计
            max=num;}                     //盢计跑Θ程
            i=0;

		}
        else if (state==OUT){             //秈虫ず
          		 state=IN;
          		 cword[i]=c;i++;          //盢じ皚
		}
		else {                            //ㄌ礛虫ず
		cword[i]=c;i++;                   //盢じ皚
		}
}
printf("程:%s\n程计%d\n",longword,max);
return 0;
}


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
printf("�п�J�@�q��r�P�Ʀr , �{���N�|��̪ܳ���r�P�̤j�Ʀr , �����Ы�ctrl+D\n");
while ((c=getchar())!=EOF)
{
		if (c=='\n'||c==' '||c=='\t'){    //��r�~
            state=OUT;
            cword[i]='\0';                //�r�굲��
            length=strlen(cword);         //�p��r�����
            num=atoi(cword);              //�N�Ʀr�ഫ�X��
            if(length>strlen(longword)){  //�Y���r��>�̪��r��
            strcpy(longword,cword);}      //�⦹�r���ܦ��̪�
            if(num>max){                  //�Y���Ʀr>�̤j�Ʀr
            max=num;}                     //�N���Ʀr�ܦ��̤j
            i=0;

		}
        else if (state==OUT){             //�i�J��r��
          		 state=IN;
          		 cword[i]=c;i++;          //�N�r���s�J�}�C
		}
		else {                            //�̵M�b��r��
		cword[i]=c;i++;                   //�N�r���s�J�}�C
		}
}
printf("�̪����r:%s\n�̤j���Ʀr%d\n",longword,max);
return 0;
}


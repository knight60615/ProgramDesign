#include<stdio.h>
int main()
{
		int c,nl,na,ne,ni,no,nu,nc,nd,total;
		nl=na=ne=ni=no=nu=nc=nd=total=0;
		printf("輸入欲測試內容，輸入完成請按ctrl+d\n");
		while((c=getchar())!=EOF)
		{
				if(c=='\n')
				{nl++;nc++;}
				if(c=='a'||c=='A')
				{na++;}
				if(c=='e'||c=='E')
				{ne++;}
				if(c=='i'||c=='I')
				{ni++;}
				if(c=='o'||c=='O')
				{no++;}
				if(c=='u'||c=='U')
				{nu++;}
				if(c>='a'&&c<='z')
				{nc++;total++;}
				if(c>='A'&&c<='Z')
				{nc++;total++;}
				if(c>='0'&&c<='9')
				{nd++;nc++;}
				
		}
		printf("number of lines %d\n",nl);
		printf("number of characters %d\n",nc);
		printf("number of digits %d\n",nd);
		printf("number of a %d\n",na);
		printf("number of e %d\n",ne);
		printf("number of i %d\n",ni);
		printf("number of o %d\n",no);
		printf("number of u %d\n",nu);
		printf("英文字母|比例\n---------------------\n");
		printf("a\t|\t%d%%\n",(na*100/total));
		printf("e\t|\t%d%%\n",(ne*100/total));
		printf("i\t|\t%d%%\n",(ni*100/total));
		printf("o\t|\t%d%%\n",(no*100/total));
		printf("u\t|\t%d%%\n",(nu*100/total));
		
		return 0;
}

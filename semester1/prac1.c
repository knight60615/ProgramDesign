#include<stdio.h>
char tl(char k)
{if (k>='A'&&k<='Z')
{k=k-('A'-'a');
return k;}
else
return k;} 
int main()
{
char c;	        
while((c=getchar())!=EOF)
{c=tl(c);
printf("%c\n",c);}						                             
return 0;   
}


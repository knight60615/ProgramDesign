#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line=0;
int PDM=0,PDS=0,CalM=0,CalS=0,LAM=0,LAS=0,PDm=100,Calm=100,LAm=100;
float AveM=0.0,AveS=0.0,Avem=100.0;
//.........................................................................
struct ScoreTable {
					char Name[20];
					int StudentNumber;
					int PD;
					int Cal;
					int LA;
					float Average;
				  }st[105];
//.........................................................................
int cmpName(const void *pa,const void *pb)
{
	struct ScoreTable *a=(struct ScoreTable *)pa;
	struct ScoreTable *b=(struct ScoreTable *)pb;
	return strcmp(a->Name, b->Name);	
}		

int cmp(const void *pa,const void *pb,int c)
{
	struct ScoreTable *a=(struct ScoreTable *)pa;
	struct ScoreTable *b=(struct ScoreTable *)pb;
	double e,f;
	switch(c)
	{
		case 1:
			e=a->StudentNumber;
			f=b->StudentNumber;
			break;
		case 2:
			e=a->PD;
			f=b->PD;
			break;
		case 3:
			e=a->Cal;
			f=b->Cal;
			break;
		case 4:
			e=a->LA;
			f=b->LA;
			break;
		case 5:
			e=a->Average;
			f=b->Average;
			break;
		case 6:
			e=strlen(a->Name);
			f=strlen(b->Name);
			break;
	}
	if(e < f )
		{return 1;}
	else
		{return -1;}
}

int cmpNum(const void *pa,const void *pb)
{return (cmp(pa,pb,1))*-1;}
int cmpPD(const void *pa,const void *pb)
{return cmp(pa,pb,2);}
int cmpCal(const void *pa,const void *pb)
{return cmp(pa,pb,3);}
int cmpLA(const void *pa,const void *pb)
{return cmp(pa,pb,4);}
int cmpAve(const void *pa,const void *pb)
{return cmp(pa,pb,5);}
int cmpNamelen(const void *pa,const void *pb)
{return (cmp(pa,pb,6))*-1;}
//.........................................................................
void printScoreTable()
{
	int i;
	printf("  �m�W\t|�@�Ǹ�\t|  P.D.\t|  Cal.\t|  L.A.\t|  Ave.\n");
	printf("--------+-------+-------+-------+-------+--------\n");
	for (i=0;i<line;i++)
	{
		printf("%s\t|",st[i].Name);
		printf("%6d\t|",st[i].StudentNumber);
		printf("%6d\t|",st[i].PD);
		printf("%6d\t|",st[i].Cal);
		printf("%6d\t|",st[i].LA);
		printf("%6.2f\n",st[i].Average);
	}
	printf("--------+-------+-------+-------+-------+--------\n");
	printf("  Ave.\t|\t|%6.2f\t|%6.2f\t|%6.2f\t|%6.2f\n" \
	 ,PDS*1.0/line,CalS*1.0/line,LAS*1.0/line,AveS*1.0/line);
	printf("  Max.\t|\t|%6d\t|%6d\t|%6d\t|%6.2f\n",PDM,CalM,LAM,AveM);
	printf("  Min.\t|\t|%6d\t|%6d\t|%6d\t|%6.2f\n\n",PDm,Calm,LAm,Avem);
}
//.........................................................................
void Search()
{
	int pdM=0,pdS=0,calM=0,calS=0,laM=0,laS=0,pdm=100,calm=100,lam=100;
	float aveM=0.0,aveS=0.0,avem=100.0;
	char c[100];
	int i,count=0;
	printf("�п�J���j�M�r�� : ");
	scanf("%s",c);
	printf("�j�M���G :\n");	
	printf("  �m�W\t|�@�Ǹ�\t|  P.D.\t|  Cal.\t|  L.A.\t|  Ave.\n");
	printf("--------+-------+-------+-------+-------+--------\n");
	for (i=0;i<line;i++)
	{
		if(strcasestr(st[i].Name,c)!=0)
		{
			printf("%s\t|",st[i].Name);
			printf("%6d\t|",st[i].StudentNumber);
			printf("%6d\t|",st[i].PD);
			printf("%6d\t|",st[i].Cal);
			printf("%6d\t|",st[i].LA);
			printf("%6.2f\n",st[i].Average);
		
			aveM=(aveM>st[i].Average)?aveM:st[i].Average;
			avem=(avem<st[i].Average)?avem:st[i].Average;
			aveS=aveS+st[i].Average;
			pdM=(pdM>st[i].PD)?pdM:st[i].PD;
			pdm=(pdm<st[i].PD)?pdm:st[i].PD;
			pdS=pdS+st[i].PD;
			calM=(calM>st[i].Cal)?calM:st[i].Cal;
			calm=(calm<st[i].Cal)?calm:st[i].Cal;
			calS=calS+st[i].Cal;
			laM=(laM>st[i].LA)?laM:st[i].LA;
			lam=(lam<st[i].LA)?lam:st[i].LA;
			laS=laS+st[i].LA;
		
			count++;
		}
	}
	if (count==0)
	{
		printf("\t\t    �d�L���\n");
		printf("--------+-------+-------+-------+-------+--------\n\n");
	}
	else
	{
		printf("--------+-------+-------+-------+-------+--------\n");
		printf("  Ave.\t|\t|%6.2f\t|%6.2f\t|%6.2f\t|%6.2f\n" \
		 ,pdS*1.0/count,calS*1.0/count,laS*1.0/count,aveS*1.0/count);	
		printf("  Max.\t|\t|%6d\t|%6d\t|%6d\t|%6.2f\n",pdM,calM,laM,aveM);
		printf("  Min.\t|\t|%6d\t|%6d\t|%6d\t|%6.2f\n\n",pdm,calm,lam,avem);
	}
}
//.........................................................................
int test(int x,int y,int z,int w)
{
	float a;
	switch(x)
	{
		case 0:
			a=st[w].PD;
			break;
		case 1:
			a=st[w].Cal;
			break;
		case 2:
			a=st[w].LA;
			break;
		case 3:
			a=st[w].Average;
	}
	switch(y)
	{
		case 0:
			return (a>z)?1:0;
		case 1:
			return (a>=z)?1:0;
		case 2:
			return (a==z)?1:0;
		case 3:
			return (a<=z)?1:0;
		case 4:
			return (a<z)?1:0;
	}
}
//.........................................................................
void AdvanceSearch()
{
	int state=-1,chose=-1,score=-1,i,k,count=0;
	char c;
	int pdM=0,pdS=0,calM=0,calS=0,laM=0,laS=0,pdm=100,calm=100,lam=100;
	float aveM=0.0,aveS=0.0,avem=100.0;
	printf("�п�J���d�߬��\n");
	printf("0)\tProgram Design\n");
	printf("1)\tCalculus\n");
	printf("2)\tLinear Algebra\n");
	printf("3)\tAverage\n");
	while(state==-1)
	{
		scanf("\n%c",&c);	
		switch(c)
		{
			case '0':
				state=0;
				printf("�z��ܤF\tProgram Design\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpPD);
				break;
			case '1':
				state=1;
				printf("�z��ܤF\tCalculus\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpCal);
				break;
			case '2':
				state=2;
				printf("�z��ܤF\tLinear Algebra\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpLA);
				break;
			case '3':
				state=3;
				printf("�z��ܤF\tAverage\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpAve);
				break;
			default:
				printf("�Э��s��J\n�п�J���d�߬�� : ");
				break;
		}
	}
	printf("�п�J�������O\n");
	printf("\t0.\t�j��     >\n");
	printf("\t1.\t�j�󵥩� >=\n");
	printf("\t2.\t����     =\n");
	printf("\t3.\t�p�󵥩� <=\n");
	printf("\t4.\t�p��     <\n");
	while(chose==-1)
	{
		scanf("\n%c",&c);
		switch(c)
		{
			case '0'...'4':
				chose=c-'0';
				break;
			default:
				printf("�Э��s��J\n�п�J�������O : ");
				break;
		}	
	}
	printf("�п�J���Ʊ��� : ");
	while(score==-1)
	{
		scanf("%d",&k);
		switch(k)
		{
			case 0 ... 100:
				score=k;
				break;
			default:
				printf("�Э��s��J\n�п�J���Ʊ��� : ");
				break;
		}
	}

	printf("�j�M���G :\n");	
	printf("  �m�W\t|�@�Ǹ�\t|  P.D.\t|  Cal.\t|  L.A.\t|  Ave.\n");
	printf("--------+-------+-------+-------+-------+--------\n");
	for (i=0;i<line;i++)
	{
		if(test(state,chose,score,i))
		{
			printf("%s\t|",st[i].Name);
			printf("%6d\t|",st[i].StudentNumber);
			printf("%6d\t|",st[i].PD);
			printf("%6d\t|",st[i].Cal);
			printf("%6d\t|",st[i].LA);
			printf("%6.2f\n",st[i].Average);
		
			aveM=(aveM>st[i].Average)?aveM:st[i].Average;
			avem=(avem<st[i].Average)?avem:st[i].Average;
			aveS=aveS+st[i].Average;
			pdM=(pdM>st[i].PD)?pdM:st[i].PD;
			pdm=(pdm<st[i].PD)?pdm:st[i].PD;
			pdS=pdS+st[i].PD;
			calM=(calM>st[i].Cal)?calM:st[i].Cal;
			calm=(calm<st[i].Cal)?calm:st[i].Cal;
			calS=calS+st[i].Cal;
			laM=(laM>st[i].LA)?laM:st[i].LA;
			lam=(lam<st[i].LA)?lam:st[i].LA;
			laS=laS+st[i].LA;
		
			count++;
		}
	}
	if (count==0)
	{
		printf("\t\t    �d�L���\n");
		printf("--------+-------+-------+-------+-------+--------\n\n");
	}
	else
	{
		printf("--------+-------+-------+-------+-------+--------\n");
		printf("  Ave.\t|\t|%6.2f\t|%6.2f\t|%6.2f\t|%6.2f\n" \
		 ,pdS*1.0/count,calS*1.0/count,laS*1.0/count,aveS*1.0/count);	
		printf("  Max.\t|\t|%6d\t|%6d\t|%6d\t|%6.2f\n",pdM,calM,laM,aveM);
		printf("  Min.\t|\t|%6d\t|%6d\t|%6d\t|%6.2f\n\n",pdm,calm,lam,avem);
	}
}
//.........................................................................
int main()
{
	int i;
	char c;
	char temp[5][100];
	FILE *fp;
	fp=fopen("./testdata","r");
	while((fscanf(fp,"%s\t%s\t%s\t%s\t%s" \
			,temp[0],temp[1],temp[2],temp[3],temp[4]))!=EOF)
	{
		for(i=2;i<=4;i++)
		{
			if (atoi(temp[i])==0)
			{
				if (temp[i][0]!='0')
				{
					printf("Error at line %d , %d ,�D�k�r��\n",line+1,i);
				}
			}
			if ((atoi(temp[i])>100)||(atoi(temp[i])<0))
			{
				printf("Error at line %d , %d ,�D�k����\n",line+1,i);
			}
		}
		strcpy(st[line].Name,temp[0]);
		st[line].StudentNumber=atoi(temp[1]);
		st[line].PD=atoi(temp[2]);
		st[line].Cal=atoi(temp[3]);
		st[line].LA=atoi(temp[4]);
		st[line].Average= \
			(st[line].PD*1.0+st[line].Cal*1.0+st[line].LA*1.0)/3;
		line++;
	}
	for (i=0;i<line;i++)
	{
		AveM=(AveM>st[i].Average)?AveM:st[i].Average;
		Avem=(Avem<st[i].Average)?Avem:st[i].Average;
		AveS=AveS+st[i].Average;
		PDM=(PDM>st[i].PD)?PDM:st[i].PD;
		PDm=(PDm<st[i].PD)?PDm:st[i].PD;
		PDS=PDS+st[i].PD;
		CalM=(CalM>st[i].Cal)?CalM:st[i].Cal;
		Calm=(Calm<st[i].Cal)?Calm:st[i].Cal;
		CalS=CalS+st[i].Cal;
		LAM=(LAM>st[i].LA)?LAM:st[i].LA;
		LAm=(LAm<st[i].LA)?LAm:st[i].LA;
		LAS=LAS+st[i].LA;
	}
	printf("����\n");
	printScoreTable();
//.........................................................................	
	while(1)
    {
        printf("�п�ܱƧǤ覡\n");
        printf("0)\t�Ǹ�\n");
        printf("1)\tP.D.\n");
        printf("2)\tCal.\n");
	    printf("3)\tL.A.\n");
		printf("4)\tAve.\n");
		printf("5)\t�W�r\n");
		printf("6)\t�W�r����\n");
		printf("7)\t�j�M\n");
		printf("8)\t�i���j�M\n");
		printf("9)\t����\n");
		scanf(" %c",&c);
		switch(c)
		{
			case '0':
				printf("�H���X��\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpNum);
				printScoreTable();
				break;
			case '1':
				printf("�HPD��\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpPD);
				printScoreTable();
				break;
			case '2':
				printf("�HCal��\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpCal);
				printScoreTable();
				break;
			case '3':
				printf("�HLA��\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpLA);
				printScoreTable();
				break;
			case '4':		
				printf("�HAve��\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpAve);
				printScoreTable();
				break;
			case '5':
				printf("�H�W�r��\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpName);
				printScoreTable();
				break;
			case '6':
				printf("�H�W�r���ױ�\n");
				qsort(st,line,sizeof(struct ScoreTable),cmpNamelen);
				printScoreTable();
				break;	
			case '7':
				printf("�j�M\n");
				Search();
				break;
			case '8':
				printf("�i���j�M\n");
				AdvanceSearch();
				break;
			case '9':
			    printf("�����{��\n");
			    return 0;
		}
	}
}

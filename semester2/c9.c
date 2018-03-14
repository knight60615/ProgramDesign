#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int loc;
void GetBinary( char c , char table[] )
{
	int shift,temp;
	for( shift = 7; shift >= 0; shift-- )
	{
		temp = ( c >>shift ) & 1;
		table[loc]=temp+'0';
		loc++;
	}
}

char *codetable[] = {	"A" , "0"	,
						"B" , "10"	,
						"C" , "110"	,
						"D" , "111"		};
int num_of_code = 4;

struct tree
{
	char *word;
	struct tree *zero;
	struct tree *one;
};

struct tree *init()
{
	struct tree *temp;
	temp = (struct tree*)malloc(sizeof(struct tree));
	temp -> word = 0;
	temp -> zero = NULL;
	temp -> one = NULL;
	return temp;
}

struct tree *maketree(char *codetable[])
{
	struct tree *root,*now;
	int i,j;
	root = init();    
	for (i=0;i<num_of_code;i++)
	{
		now = root;
		for (j=0;j<strlen(codetable[2*i+1]);j++)        
		{
			if (codetable[2*i+1][j] == '1')
			{
				if (now -> one == NULL) 
					now -> one = init();
				now = now -> one;
			}
			else 
			{
				if (now -> zero == NULL) 
					now -> zero = init();
				now = now -> zero;
			}                   
		}
		now -> word = codetable[2*i];
	}
	return root;
}

int main(int argc,char *argv[])
{
	FILE *FilePointer;
	char c,table[500];
	int i;
	struct tree *root,*now;
	FilePointer = fopen( argv[1] , "r" ) ;
	loc = 0;
	while( ( c = fgetc( FilePointer ) ) != EOF )
		GetBinary( c , table );
/*	for( i = 0 ; i < loc ; i++ )
		printf( "%c" , table[i] );
	printf( "\n" );*/
	
	root = maketree (codetable);
	now = root;
	
	
	for( i = 0 ; i <= loc ; i++ )
	{
			if ( ( now -> word ) != 0 )
			{
				printf("%s",now -> word);
				now = root;
			}
			if (i==loc)
				break;
			else if (table[i] == '1')
				now = now -> one;
			else 
				now = now -> zero;
	}
	printf( "\n" );
	return 0;
}

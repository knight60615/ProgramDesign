#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
   int i;
   char str[200];
   for(i = 1; i< argc; i++){
      
      strcat(str, argv[i]);
      strcat(str, " ");
      }
   for(i = strlen(str)-2; i >= 0; i--){
      
      printf("%c", str[i]);
   }   
   return 0;

}

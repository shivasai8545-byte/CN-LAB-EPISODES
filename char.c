#include<stdio.h>
int main()
{
char a[100];
int i,count = 0;
 printf("Enter the character to count");
 gets(a);
 for(i=0;a[i]!='\n';i++){
 count++;
  }
     printf("Total characters: %d\n", count);

 }
 
 

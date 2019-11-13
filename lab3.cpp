#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "stack.c"

int main()
{
	char c;
	stack ListKo;
	int length;
	int position;
	int quit=0;
	char temp[4];


    ListKo.top=-1;
	while (quit==0)
	{
	printf("\n-");
	c=getche();
	switch (c)
	{
	case 'e': //done
	{
		if(empty(&ListKo)==1){
               printf(" Empty Stack!\n");
               }
        else if(empty(&ListKo)==0){
               printf(" May Values na sa loob\n");
               }	     
	}
	break;
	case 't': //done
	{
	     printf(" The Top Value is: %c\n", top(&ListKo));
	}
	break;
	case '+': //done
	{
     if(ListKo.top==3){
         printf(" %d Full\n", full(&ListKo));
         } 
      else{  
        printf(" ");
        scanf("%s", temp);
        push(&ListKo, temp);
        }
	}
	break;
	case 'q':  //done
	{
		quit=1;
		printf(" Thank You!\n");
		getch();
		
	}
	break;
	case '-': //done
	{
         if(ListKo.top>=0){
         pop(&ListKo);
         }
         else{
              printf(" Underflow!\n");
             }
	}
	break;
	case 'c': //done
	{
		clear(&ListKo);

	}
	break;
	case 'f':  //done
	{
		if(full(&ListKo)==1){
               printf(" Stack Is FULL!\n");
               }
        else if(full(&ListKo)==0){
               printf(" Maluwag pa\n");
               }
	}break;
	case 's': //done
	{
		if(empty(&ListKo)==1){
               printf(" Empty Stack!\n");
               }
        else if(empty(&ListKo)==0){
               printf(" ");
               display(&ListKo);
               printf("\n");
               }
	}
	break;
	default:
		{
			printf("\n\nYou have entered an incorrect Option!\n");
		}	break;
    }
	}
	return 0;
}

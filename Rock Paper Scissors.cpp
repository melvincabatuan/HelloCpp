#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*Brought to you by RCola*/
void compare(int *p1, int *p2);     //Prototyping of Functions
main()
{
      int p1, p2;
      
      printf("Brought to you by Ivan\n");
      printf("1 - Rock\n2 - Paper\n3 - Scissors");
      printf("\nPlayer 1: ");
      scanf("%d", &p1);
      system("cls");
      printf("1 - Rock\n2 - Paper\n3 - Scissors");
      printf("\nPlayer 2: ");
      scanf("%d", &p2);
      system("cls");
      compare(&p1, &p2);
}
void compare(int *p1, int *p2){                 //The values are passed into functions by reference
      if (*p1 == *p2)
      printf("Try Again!");
      else if(*p1 == 1 && *p2 ==2)                   //comparison
           printf("Player 2 Wins!");
      else if(*p1 == 1 && *p2 ==3)
           printf("Player 1 Wins!");
      else if(*p1 == 2 && *p2 ==1)
           printf("Player 1 Wins!");
      else if(*p1 == 2 && *p2 ==3)
           printf("Player 2 Wins!"); 
      else if(*p1 == 3 && *p2 ==1)
           printf("Player 2 Wins!");
      else if(*p1 == 3 && *p2 ==2)
           printf("Player 1 Wins!");
      getch();
      }   

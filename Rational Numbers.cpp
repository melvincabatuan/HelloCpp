/*The program is brought to you by ®©ola™ (if you know how to type ®©
                                                              by keyboard, then you are ME*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Creating the structure for the rational number
struct rational{
       int num1;
       int num2;
       };

//Prototying Functions
void initialize(struct rational *number, int up, int down);
void display(struct rational *disp);
void multiply(struct rational *r1, struct rational *r2, struct rational *prod);
void divide(struct rational *r1, struct rational *r2, struct rational *quo);
void add(struct rational *r1, struct rational *r2, struct rational *sum);
void subtract(struct rational *r1, struct rational *r2, struct rational *diff);
void simplify(struct rational *rat);


//Main       
main(int argc, char *argv[])
{
         struct rational number1, number2, number3;
         int num1, num2, den1, den2;
         printf("Enter the Numerator and Denominator of Rational #1: ");
         scanf("%d %d", &num1, &den1);
         printf("Enter the Numerator and Denominator of Rational #2: ");
         scanf("%d %d", &num2, &den2);        
         initialize(&number1, num1, den1);
         initialize(&number2, num2, den2);
         simplify(&number1);
         display(&number1);
         getch();
         
}


//Codes of functions are written here
void initialize(struct rational *number, int up, int down)
{
     number->num1 = up;
     number->num2 = down;
}


void display(struct rational *disp)
{
     printf("Your Number is %d/%d", disp->num1, disp->num2);
}

void multiply(struct rational *r1, struct rational *r2, struct rational *prod)
{
     prod->num1 = r1->num1 * r2->num1;
     prod->num2 = r1->num2 * r2->num2;
}

void divide(struct rational *r1, struct rational *r2, struct rational *quo)
{
     quo->num1 = r1->num1 * r2->num2;
     quo->num2 = r1->num2 * r2->num1;
}



void add(struct rational *r1, struct rational *r2, struct rational *sum)
{
     sum->num1 = r1->num1*r2->num2 + r2->num1*r1->num2;
     sum->num2 = r1->num2 * r2->num2;
}

void subtract(struct rational *r1, struct rational *r2, struct rational *diff)
{
     diff->num1 = r1->num1*r2->num2 - r2->num1*r1->num2;
     diff->num2 = r1->num2 * r2->num2;
}

void simplify(struct rational *rat)
{
     int a, b, com;
     if(rat->num1 > rat->num2)
     {
        a = rat->num1;
        b = rat->num2;
     }
     else
     {   
        a = rat->num2;
        b = rat->num1;  
     }   
               
     while(b!=0)
     {
      com = a%b;
      a = b;
      b = com;
     }
     rat->num1 = rat->num1/a;
     rat->num2 = rat->num2/a;
}
//The program is brought to you by ®©ola™

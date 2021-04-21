#include<stdio.h>
#include<stack>
using namespace std;

int main(void){
	
   stack <int> stacks;
   int number;
   printf("Enter a Decimal Value: "); //decimal input
   scanf("%d", &number); //scans input number
   printf("Decimal to Binary Value: "); //binary output
   
   //successive division decimal to binary
   //original no. divided by 2 
   //1 symbolizes as the remainder
   //0 symbolizes as no remainder
   //divide next no.2 by 2 and if its 0, as as a result, it pushes remainder

   while(number > 0) { //while the number is bigger than 0
      int remainder = number % 2; //this computes for the remainder
      number = number / 2; //divides the computed remainder/number by 2
      stacks.push(remainder); //pushes the remainder after dividing the number by 2
   }
   
   while(!stacks.empty()) { //while the stack is not empty
   	  
      int binary;          
      binary = stacks.top(); //the variable is set to the top element in the stack
      stacks.pop(); //this removes the element at the top of the stack
      printf("%d", binary); //prints the binary value at the top of the stack 
   }
}


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30


typedef struct{
        char infix[MAX];
        char postfix[MAX];
        char opstack[MAX];
        char buffer;
        int operatortop;
        int operandtop;
        }conv;
        
void compare(conv *temp);
void init(conv *temp);
void push(conv *temp, char buffer);
void add(conv *temp, char buff);
void add1(conv *temp, char buff);
void pop(conv *temp);
void add2(conv *temp, char buff);
void superpop(conv *temp);

conv myList;

main(){

       init(&myList);
       printf("Infix to Postfix Converter v10\n");
       printf("By Ivan Ylagan\n\n");
       printf("Insert Infix: ");
       scanf("%s", myList.infix);
       compare(&myList);
       superpop(&myList);
       printf("\n\nINFIX: %s\n", myList.infix);
       printf("POSTFIX: %s", myList.postfix);
       getch();
       }


void init(conv *temp){
     temp->operatortop=-1;
     temp->operandtop=-1;
     }

void compare(conv *temp){
     int ctr;
     for(ctr=0;ctr<strlen(temp->infix);ctr++){
          if(temp->infix[ctr] == '*' || temp->infix[ctr] == '/' || temp->infix[ctr] == '-' || temp->infix[ctr] == '+' || temp->infix[ctr] == '^'){
                              add(&myList, temp->infix[ctr]);
                              continue;
                         }
          if(temp->infix[ctr]=='('){
                                    add2(&myList, temp->infix[ctr]);
                                    continue;
                                    }
          if(temp->infix[ctr]==')'){
                                    pop(&myList);
                                    continue;
                                    }
          else{
                              add1(&myList, temp->infix[ctr]);
                              continue;
              }
}
}

void add2(conv *temp, char buff){
     temp->operatortop++;
     temp->opstack[temp->operatortop] = buff;
     }

void add(conv *temp, char buff){
     int cp1, cp2;

    if(temp->operatortop!=-1){                                             
          switch(temp->opstack[temp->operatortop]){
          case '^': { cp1=5; } break;
          case '*': { cp1=4; } break;
          case '/': { cp1=4; } break;
          case '+': { cp1=3; } break;
          case '-': { cp1=3; } break;
          case '(': { cp1=0; } break;
          }
          switch(buff){
          case '^': { cp2=5; } break;
          case '*': { cp2=4; } break;
          case '/': { cp2=4; } break;
          case '+': { cp2=3; } break;
          case '-': { cp2=3; } break;
          case '(': { cp1=6; } break;
          }
     if(cp1 > cp2 || cp1 == cp2){
            add1(&myList, temp->opstack[temp->operatortop]);
            temp->opstack[temp->operatortop] = buff;
            return;
}
     if (cp1 < cp2){
            temp->operatortop++;
            temp->opstack[temp->operatortop] = buff;
            return;
            }           
          }
     else{
     temp->operatortop++;
     temp->opstack[temp->operatortop] = buff;   
     return;      
          }
     }

void add1(conv *temp, char buff){
     temp->operandtop++;
     temp->postfix[temp->operandtop] = buff;
     }
void pop(conv *temp){
        int ctr;
        for(ctr=temp->operatortop;ctr>0;ctr--){
             if(temp->opstack[temp->operatortop]!='('){
             add1(&myList, temp->opstack[temp->operatortop]);
                           temp->operatortop--;

                           }
             }
             temp->operatortop--;
             }
     

void superpop(conv *temp){
     int ctr;
     if(temp->operatortop!=-1){
          for(ctr=temp->operatortop;ctr>-1;ctr--){
                             add1(&myList, temp->opstack[ctr]);
                             }   
                             return;   
                             }
     else{
                              return;  
         }
}                                        
     

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

typedef struct Node1{//For Operator Link-type Stack
        char OperatorC;
        struct Node1 *next;
        }Operator;
typedef struct{
        int size;
        Operator *start;
        }Link1; 

//**********************************************//

typedef struct Node2{//For Operand Link-type Stack
        char OperandC;
        struct Node2 *next;
        }Operand;
typedef struct{
        int size;
        Operand *start;
        }Link2;     
       
typedef struct{
        char infix[MAX];
        }Infix;




void evaluation(Link1 *temp, Link2 *buff, Infix *original);
void initialize(Link1 *temp, Link2 *buff);
void toOperator(Link1 *temp, Link2 *buff, char c);
void toOperand(Link1 *temp, Link2 *buff, char c);
void toOperatorN(Link1 *temp, Link2 *buff, char c);
void superpop(Link1 *temp, Link2 *buff);
void displayoperator(Link1 *temp);
void displayoperand(Link2 *buff);


Link1 linkoperator;
Link2 linkoperand;
Infix o;

main(){

       initialize(&linkoperator, &linkoperand);
       printf("Infix to Postfix Converter v20\n");
       printf("By Ivan Ylagan\n\n");
       printf("Insert Infix: ");
       scanf("%s", o.infix);
       evaluation(&linkoperator, &linkoperand, &o);


       getch();
       }

void evaluation(Link1 *temp, Link2 *buff, Infix *original){
     int ctr;
     
     printf("Current                 Operand                      Operator");
     for(ctr=0;ctr<strlen(original->infix);ctr++){
          if(original->infix[ctr] == '*' || original->infix[ctr] == '/' || original->infix[ctr] == '-' || original->infix[ctr] == '+' || original->infix[ctr] == '^'){
    
                              toOperator(&linkoperator, &linkoperand, original->infix[ctr]);
                              
                         }
          else{
                               toOperand(&linkoperator, &linkoperand, original->infix[ctr]);
                              
               }
     printf("\n%c", original->infix[ctr]);
     printf("                       ");
     displayoperand(&linkoperand);
     printf("\t\t\t\t");
     displayoperator(&linkoperator);
     printf("\n");
      
}
     superpop(&linkoperator, &linkoperand);
     printf("\n                        ");
     displayoperand(&linkoperand);         
}

void initialize(Link1 *temp, Link2 *buff){
     temp->size = -1;//for operator stack
     temp->start = NULL;
     buff->size = -1;//for operand stack
     buff->start = NULL;
     }


//Link1 for operator
//Link2 for operand
void toOperator(Link1 *temp, Link2 *buff, char c){
    Operator *Compare1;
    Operator *Compare2;
    Operator *New;
    Operator *Find;
    int ctr=0;
    int cp1, cp2;

    if(temp->size!=-1){   
     Compare1 = temp->start;
     while(ctr<temp->size){
                   Compare1 = Compare1->next;   
                   ctr++;    
                           }   
                                                                                                        
          switch(Compare1->OperatorC){
          case '^': { cp1=5; } break;
          case '*': { cp1=4; } break;
          case '/': { cp1=4; } break;
          case '+': { cp1=3; } break;
          case '-': { cp1=3; } break;
          case '(': { cp1=0; } break;
          }
          switch(c){
          case '^': { cp2=5; } break;
          case '*': { cp2=4; } break;
          case '/': { cp2=4; } break;
          case '+': { cp2=3; } break;
          case '-': { cp2=3; } break;
          case '(': { cp1=6; } break;
          }
       
     if(cp1 > cp2 || cp1 == cp2){
            
            toOperand(&linkoperator, &linkoperand, Compare1->OperatorC);
            Compare1->OperatorC = c;
            return;
            }   
     if (cp1 < cp2){
            New = (Operator*)malloc(sizeof(Operator));
            New->OperatorC = c;
            New->next = NULL;
            Compare1->next = New;
            temp->size++; 
                         
            return;
            }  
            }

     else{
          toOperatorN(&linkoperator, &linkoperand, c); 
          }     
          
     
   
     
}

//Link1 for operator
//Link2 for operand
void toOperand(Link1 *temp, Link2 *buff, char c){
    Operand *New;
    Operand *Find;
    int ctr=0;
        if(buff->size==-1){
                New = (Operand*)malloc(sizeof(Operand));
                New->OperandC = c;
                New->next= NULL;
                buff->start = New;           
                buff->size++;
                           }
        else{
             Find = buff->start;
             while(ctr<buff->size){
                              Find = Find->next; 
                              ctr++;     
                                    }
                New = (Operand*)malloc(sizeof(Operand));
                New->next = NULL;
                New->OperandC = c;
                Find->next = New;   
                buff->size++;          
     } 
}

void toOperatorN(Link1 *temp, Link2 *buff, char c){
     Operator *New1;
     Operator *Find1;
     int ctr=0;
     if(temp->size==-1){
     New1 = (Operator*)malloc(sizeof(Operator));   
     New1->next = NULL;
     New1->OperatorC = c;
     temp->start = New1;
     temp->size++;                        
          }  
                        
     
     
     else{
     Find1 = temp->start;
     while(ctr<temp->size){
                Find1 = Find1->next;
                ctr++;            
                            }
     New1 = (Operator*)malloc(sizeof(Operator));   
     New1->next = NULL;
     New1->OperatorC = c;
     Find1->next = New1;
     temp->size++;
     }
     }

//Link1 for operator
//Link2 for operand     

void superpop(Link1 *temp, Link2 *buff){
     Operator *Find; 
     Operator *Removed;
     int ctr;
     int ctr1=0;

          for(ctr=temp->size;ctr>0;ctr--){
                             Find = temp->start;  
                             while(ctr1<ctr-1){
                                          Find = Find->next; 
                                          ctr1++;         
                                                   }
                             
                             Removed = Find->next;
                             toOperand(&linkoperator, &linkoperand, Removed->OperatorC);
                             Find->next = Removed->next;    
                             free(Removed);   
                             temp->size--;                                    
                             } 
   
           Find = temp->start;
           toOperand(&linkoperator, &linkoperand, Find->OperatorC);
           temp->start = NULL;                  
           temp->size--;

                             

}                                        
  
void displayoperator(Link1 *temp){
     Operator *Find1;
     Find1 = temp->start;
    
     while(Find1!=NULL){
                 printf("%c", Find1->OperatorC);
                 Find1 = Find1->next;
                 }                        
     
     
     }

void displayoperand(Link2 *buff){
     Operand *Find;
     Find = buff->start;
     while(Find!=NULL){
                       
                 printf("%c", Find->OperandC);
                 Find = Find->next;
                 
                 
                 } 
}

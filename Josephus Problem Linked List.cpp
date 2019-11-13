#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10


typedef struct HEAD{
        char count[MAX];
        struct HEAD *next;
        }node;
        
typedef struct{
        int size;
        node *start;
        int increment;
        char buffer[MAX];
        char display[MAX];
        }list;

       list ListKo;
       node NodeKo;

void init(list *temp);
void insert(list *temp, char name[MAX]);
void display(list *temp);
void remove(list *temp);
void finalnode(list *temp);
void recursive(list *temp, node *Current);

//this remove initializes the starting point of the increment
//starting from temp->start, this function tries to look for the node with content "name"
//If the function sees it, it makes that node to be the starting node for the next increment
void remove(list *temp, char name[MAX]){
     node *Find;                 

     Find = temp->start;

     while(strcmp(Find->count, name)!=0){
                   Find = Find->next;
                               }

              //this function is where the increment happens, and the linking of nodes
              //Let Find be the starting node for the increment
              recursive(&ListKo, Find);
      
     }
     
//
void recursive(list *temp, node *Current){
     node *Find;
     node *Previous;
     node *Removed;
     node *Compare;
     node *aw;
     
     Compare = temp->start;
     int inc=0;
     Find = Current;
     

     while(temp->size!=0){//do this while size is still not = to 0
     printf("\n%s                             ", Find->count);
     display(&ListKo);
     
     while(inc<temp->increment-1){               
                          Previous = Find;//looks for the previous and Find node to be evaluated
                          Find = Find->next;
      
                          if(Find==NULL){//if the node is seen to be NULL do the following
                                      Find = temp->start;     
                                      inc++;
   
                                        }//end of if 1
                          else{
                               inc++;
                               }//end of else 1
                                  
                                  }//end of while 2
                if(Find==Compare){//if Find is temp->start, Find->next be the starting node
                       temp->start = Find->next;
                       aw = Find->next;
                       strcpy(temp->display, Find->count);
                       free(Find);
                       temp->size--;
                       strcpy(temp->buffer, aw->count);//copy the next head and input to remove();
                       printf("\t\t\t%s", temp->display); 
                       remove(&ListKo, temp->buffer);//loop
                                  }//end of if 2
                else{
                       if(Find->next==NULL){//if Find->next is null, it gets the content of the starting node, then input to remove();
                       Previous->next = Find->next;//link link
                       strcpy(temp->display, Find->count);//gets the next head
                       aw = temp->start;
                       free(Find);
                       temp->size--;
                       strcpy(temp->buffer, aw->count);
                       printf("\t\t\t%s", temp->display); 
                       remove(&ListKo, temp->buffer);//loop
                       }//end of if 3
                       
                       else{
                       Previous->next = Find->next;//link link
                       strcpy(temp->display, Find->count);//gets the next head
                       aw = Find->next;
                       free(Find);
                       temp->size--;
                       strcpy(temp->buffer, aw->count);
                       printf("\t\t%s", temp->display); 
                       remove(&ListKo, temp->buffer);//loop                          
                            }//end of else 3
                       }//end of else 2
        
                     }//end of main while
  
              
     }    

main(){
       int number;
       char temp[MAX];
       int ctr;
       int increment;
 
       init(&ListKo);
       printf("Josephus Problem\n");
       printf("Enter number of People: ");
       scanf("%d", &number);
       for(ctr=0;ctr<number;ctr++){
                    printf("Character: ");
                    scanf("%s", temp);
                    insert(&ListKo, temp);               
                                   
                    }

       printf("\nEnter the increment: ");
       scanf("%d", &ListKo.increment);
       printf("Enter the First person to be removed: ");
       scanf("%s", temp);
       printf("Head                   Circular Link List              Output");                  
       remove(&ListKo, temp);
       printf("\n");
       display(&ListKo);
       printf("                            ");
       display(&ListKo);
       printf("\t\t\t");
       display(&ListKo);
       printf("\n");
       system("PAUSE");
       }
       

void init(list *temp){//initialization
     temp->size = -1;
     temp->start = NULL;
     }
   
void insert(list *temp, char name[MAX]){
     node *Find;
     node *New;
     int ctr=0;
     if(temp->size==-1){//first input of node: 
           New = (node*)malloc(sizeof(node));//creates new node
           //node contents
           strcpy(New->count, name);
           New->next = NULL;
           //link link: New be the start;
           temp->start = New;
           temp->size++;         
                       }
     else{
          Find = temp->start;
          while(ctr<temp->size){//node traversal
                   Find = Find->next;
                   ctr++;             
                   }
           New = (node*)malloc(sizeof(node));//creates new node
           //node contents
           strcpy(New->count, name);
           New->next = NULL;
           //link New to the Node in the link list
           Find->next = New;
           temp->size++;     
           }  
     }       
       
void display(list *temp){//displays the node
     node *Find;
     node *New;
     Find = temp->start;
     int ctr=0;
     while(Find!=NULL){//while the node is still not null display the content;
             printf("%s ",Find->count);
             Find = Find->next;//go to the next node;
             ctr++;
             }
             }

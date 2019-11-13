#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//maximum waiting time is 10minutes (I made this to be realistic)
//take note that maximum waiting time is different from the longest waiting time
//longest waiting time varies amongst the waiting time for each customer
//minute = minute + x; means that within the period, a costumer waits for x minutes
//moreover, his/her waiting time is accumulated to minute which eventually reach the n period of time

typedef struct{
        int cNumber;
        int wTime;
        }Costumer;

typedef struct{
        int front;
        int rear;
        float cSize;
        Costumer Custom[150];//Max Customers which the shop can accomodate
        }Queue;


void initialize(Queue *temp){
     temp->cSize=0;
     temp->front=0;
     temp->rear=-1;
     }


void timeflow(Queue *temp, int time){
     int minute;
     int k, j;//rand
     int x;//rand for waiting time
     int number=0;
     int a,b;
     
     for(minute=0;minute<time;minute){
             if(temp->rear<temp->front){
                 k = rand() % 4;
                   if(k==1){
                            temp->rear++;
                            temp->cSize++;                        
                            x = 0;
                            temp->Custom[temp->rear].wTime = x;
                            temp->Custom[temp->rear].cNumber = temp->rear+1; 
                            minute = minute + x;
                            printf("k = %d ----------------------\n", k);
                            printf("Costumer Number: %d\n", temp->Custom[temp->rear].cNumber);
                            printf("Waiting Time is: %d\n", temp->Custom[temp->rear].wTime);
                            printf("----------------------------\n");

                            }
                   if(k==2){
                            temp->rear++;                     
                            x = 0;
                            temp->Custom[temp->rear].wTime = x;
                            temp->Custom[temp->rear].cNumber = temp->rear+1; 
                            minute = minute + x;
                            printf("k = %d ----------------------\n", k);
                            printf("Costumer Number: %d\n", temp->Custom[temp->rear].cNumber);
                            printf("Waiting Time is: %d\n\n", temp->Custom[temp->rear].wTime);
                            
                            temp->rear++;                     
                            x = 0;
                            temp->Custom[temp->rear].wTime = x;
                            temp->Custom[temp->rear].cNumber = temp->rear+1; 
                            minute = minute + x;
                            printf("Costumer Number: %d\n", temp->Custom[temp->rear].cNumber);
                            printf("Waiting Time is: %d\n", temp->Custom[temp->rear].wTime);
                            printf("----------------------------\n");
                            temp->cSize+=2; 
                            }                 
                     else{
                          continue;
                          }              
             }//if empty queue
                else{
                                    
                j = rand() % 4;
                   if(j==1){
                            temp->front++;
                            temp->rear++;
                            temp->cSize++;                        
                            x = rand() % 11;
                            temp->Custom[temp->rear].wTime = x;
                            temp->Custom[temp->rear].cNumber = temp->rear+1; 
                            minute = minute + x;
                            printf("k = %d ----------------------\n", j);
                            for(a=temp->front;a<=temp->rear;a++){
                            printf("Costumer Number: %d\n", temp->Custom[a].cNumber);
                            printf("Waiting Time is: %d\n\n", temp->Custom[a].wTime);
                            }
                            printf("----------------------------\n");

                            }//end of if at else                    
                   if(j==2){
                            temp->front++;
                            temp->cSize+=2;
                            temp->rear++;                     
                            x = rand() % 11;
                            temp->Custom[temp->rear].wTime = x;
                            temp->Custom[temp->rear].cNumber = temp->rear+1; 
                            minute = minute + x;
                            temp->rear++;                     
                            x = rand() % 11;
                            temp->Custom[temp->rear].wTime = x;
                            temp->Custom[temp->rear].cNumber = temp->rear+1; 
                            minute = minute + x;
                            printf("k = %d ----------------------\n", j);
                            for(a=temp->front;a<=temp->rear;a++){
                            printf("Costumer Number: %d\n", temp->Custom[a].cNumber);
                            printf("Waiting Time is: %d\n\n", temp->Custom[a].wTime);
                            }
                            printf("----------------------------\n");                                               
                            } //end of if at else
                            
                   else if(j==0 || j ==3){
                            printf("On Hold---------------------\n", j);
                            for(a=temp->front;a<=temp->rear;a++){
                            printf("Costumer Number: %d\n", temp->Custom[a].cNumber);
                            printf("Waiting Time is: %d\n\n", temp->Custom[a].wTime);
                            }
                            printf("----------------------------\n");                          
                        }        
                            }                               
     }//end of for loop

     }//end of function
     
int longestwTime(Queue *temp){//this function finds the longest waiting time amongst the costumers
     int a,b,c;
     int max;
     a=0;
     max=0;
     while(a<=temp->rear){
          b = temp->Custom[a].wTime;
          if(b>max){
                max = b; 
                a++;
                continue;
                 
                  }
          else{
                 a++;
                continue;           
               }             
          }
                          return max;//return the value needed
     }

main(){
       Queue MainQueue;
       int n;
       int x,y;
       float ctr;//costumer length
       float timel;//total waiting time of costumers
       float z;
       srand (time(NULL));

       initialize(&MainQueue);
       printf("Welcome to Customer Simulator\n");
       printf("Please enter a Period Time n: ");
       scanf("%d", &n);
       timeflow(&MainQueue, n); //this function simulates up to n period of time
       
       printf("\nSummary\n");
       printf("Time Interval: %d\n", n);
       ctr = 0;
       timel = 0;
       for(x=0;x<=MainQueue.rear;x++){
                   timel = timel + MainQueue.Custom[x].wTime;//getting the total waiting time of the costumers
                   }
       printf("Ave: %.0f/%.0f = %.2f\n", timel, MainQueue.cSize, timel/MainQueue.cSize);
       printf("Max: %d", longestwTime(&MainQueue));
       getch();
       }

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


typedef struct{
        int cNumber[300];//minutes d2
        int front;
        int rear;
        float satisfied;
        float longest;
        float total;
        }Queue;

       
void longes(Queue *temp, int buff){
     if(buff>temp->longest){
                    temp->longest = buff;        
                            }
     else{
          return;
          }
     }

void timeflow(Queue *temp, int n){
     int minute;
     int k;
     int waittime=0;

    
     for(minute=0;minute<=n;minute++){//evaluated per increment of minute
             k = rand() % 3;          //generates random number
             if(k==1){
                            if(temp->rear==temp->front){
                            temp->rear++;
                            temp->satisfied++;
                            temp->cNumber[temp->rear] = minute;
                            temp->total = temp->total + waittime;
                            }
                            else{
                            temp->front++;
                            temp->satisfied++;                                 
                            waittime = minute - temp->cNumber[temp->front];
                            temp->total = temp->total + waittime;
                                    if(waittime>temp->longest){
                                                    temp->longest = waittime;           
                                                               }
                                    else{
                                         continue;
                                         }
                                 }              
                              
                      }
                      
             if(k==2){
                            if(temp->rear==temp->front){
                            temp->rear++;
                            temp->satisfied+=2;
                            temp->cNumber[temp->rear] = minute;
                            temp->rear++;
                            temp->cNumber[temp->rear] = minute;
                            temp->total = temp->total + waittime;
                            }
                            else{
                            temp->front++;
                            temp->satisfied+=2;                                 
                            waittime = minute - temp->cNumber[temp->front];
                            temp->total = temp->total + waittime;
                                    if(waittime>temp->longest){
                                                    temp->longest = waittime;           
                                                               }
                                    else{
                                         continue;
                                         }
                            temp->rear++;
                            temp->satisfied+=2;
                            temp->cNumber[temp->rear] = minute;
                            temp->rear++;
                            temp->cNumber[temp->rear] = minute;
                            temp->total = temp->total + waittime;                              
                                 }              
                              
                      }
             if(k==0 || k==3){
                     minute++;
                     }                                                  
}//end of for loop                                                            
        }
     
main(){
       srand(time(NULL));
       Queue q;
       q.rear=-1;   //intializations
       q.front=-1;
       q.longest=0;
       q.total=0;
       int n;
       printf("Enter n: ");
       scanf("%d", &n);
       timeflow(&q, n);
       printf("Time: %d\n", n);
       printf("Total # Served: %f\n", q.satisfied);
       printf("Average Waiting Time: %.0f/%.0f = %.2f\n", q.total, q.satisfied, q.total/q.satisfied);
       printf("Longest Waiting Time: %f\n", q.longest);
            
       system("PAUSE");
       }

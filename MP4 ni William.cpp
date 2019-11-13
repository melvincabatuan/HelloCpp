#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 100

typedef struct{
        int front;
        int rear;
        int items[MAX];
        float timy[MAX];
        }queue;
        
void initQueue(queue* fQ){
     fQ->front = 0;
     fQ->rear = 0;
     }
     
void insertQueue(queue* fQ, int item, float timing){
     fQ->rear++;
     if(fQ->rear>=MAX){
                       fQ->rear=0;
                       }
     fQ->timy[fQ->rear] = timing;
     fQ->items[fQ->rear] = item;
     }
     
float removeQueue(queue* fQ){
    fQ->front++;
    if(fQ->front>=MAX){
                       fQ->front=0;
                       }
    return fQ->timy[fQ->front];
    }
    
int isEmpty(queue* fQ){
     if(fQ->front==fQ->rear){
                             return 1;
                             }
     return 0;
     }
     
main(){
       queue flow;
       int times, cust, k, t; 
       float wait1 = 0, wait = 0, served=0, minute , lwait = 0, d;
       srand(time(NULL));
       initQueue(&flow);
       printf("Enter time: ");
       scanf("%d", &t);
       for(minute=0;minute<=t;minute++){
          k=rand()%4;
          if(isEmpty(&flow)==0){
                             wait = removeQueue(&flow);
                             served++;//gets ko to
                             d = minute - wait;
                             if(lwait==0){
                                          lwait = d;
                                          }
                             else if(lwait<d){
                                  lwait = d;
                                  }
                             wait1 = wait1 + d;
                             }
          if(k == 1){//nakuha ko n 2
               insertQueue(&flow, 1, minute);
               }
          if(k == 2){
               insertQueue(&flow, 1, minute);
               insertQueue(&flow, 1, minute);
               }
          if(k == 0 || k ==3){
               if(isEmpty(&flow)==0){
                                     }
               }
          if(minute==30){
                         printf("Time\t Served\t Average wait\t Longest wait\n");
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t    %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==60){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==120){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==180){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==240){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==300){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==360){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==480){  
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
          if(minute==t && minute!=30 && minute!=60 && minute!=120 && minute!=180 && minute!=240 && minute!=480 && minute!=300 && minute!=360){
                         printf("%.00f\t %.00f\t %.02f/%.00f=%.02f\t %.00f\n", minute, served, wait1, served, wait1/served, lwait);
                         getch();
                         }
                         }//hanggang d2
       }//end of main

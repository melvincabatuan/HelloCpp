#include<stdio.h>
#include<conio.h>

#define max 25

typedef struct{
        int items[max];
        int size;
        }List;

void initialize(List *ko);
void display(List *ko);
void insertTwo(List *ko, int item1, int item2);
void removeAll(List *ko);




main(int argc, char *argv[]){
         List cat1;
         initialize(&cat1);
         insertTwo(&cat1, 1, 2);
         insertTwo(&cat1, 3, 4);
         insertTwo(&cat1, 5, 6);
         insertTwo(&cat1, 7, 8);
         insertTwo(&cat1, 9, 10);
         display(&cat1);
         removeAll(&cat1);
         display(&cat1);
         getch();

}       

void initialize(List *ko){
     ko->size = 0;
     }

void insertTwo(List *ko, int item1, int item2){
     int comp,x,y;
     if(ko->size == 0){
     ko->size++;
     ko->items[0] = item1; //Even Number Address of array
     ko->items[1] = item2; //Odd  Number Address of array
     }
     else{
     ko->size+=2;
     x = ko->size;
     for(comp=x-1;comp>=0;comp){
     ko->items[comp] = ko->items[comp-=2];
     }
     for(comp=x;comp>=1;comp){
     ko->items[comp] = ko->items[comp-=2];
     }

     }
          ko->items[0] = item1; //Even Number Address of array
     ko->items[1] = item2; //Odd  Number Address of array
}
void display(List *ko){
     int pos;
     for(pos=0;pos<=ko->size;pos++)
     printf("%d\n", ko->items[pos]);
     }

void removeAll(List *ko){
     int pos;
     for(pos=0;pos<=ko->size;pos++){
     ko->items[pos] = NULL;
     ko->size = NULL;
     }
     
     
     }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE{
        char letter;
        int weight;
        struct NODE *left;
        struct NODE *right;
        struct NODE *next;
        }nodes;

typedef struct{
        int size;
        nodes *start;
        }list;

nodes *New(char letter, int weight){
      nodes *NewNode;
      NewNode=(nodes*)malloc(sizeof(nodes));
      NewNode->letter = letter;
      NewNode->weight = weight;
      NewNode->left = NULL;
      NewNode->right = NULL;
      NewNode->next = NULL;
      return NewNode;
      }

void display(nodes* temp, int level) {   //paki disregard po itong function =)
    int ctr;  
    
    
    if(temp != NULL) {    
        printf("[%c:%d]",temp->letter, temp->weight);
        //traverse to the leftmost side of the tree
        if(temp->left != NULL) {

            
            printf("\n");
            for(ctr=0;ctr<=level;ctr++) {
                printf("\t  ");
            }
            printf("<-");
            
            display(temp->left, level+1);//recursive
        }
        //traverse to the rightmost side of the tree
        if(temp->right != NULL) {


            printf("\n");
            for(ctr=0;ctr<=level;ctr++) {
                printf("\t  ");
            }
            printf("->");
            display(temp->right, level+1);//recursive
        }
            
    }
            return;
}



main(){
       int *w;
       int sorted=0;
       int aw=0;
       char *lii;
       int ctr=0;
       int size=0;
       list l;
       char a;
       int b;
       nodes *NEW;
       nodes *NEED;
       nodes *FIND;
       nodes *ROOT;
       nodes *LEFT;
       nodes *RIGHT;
       nodes *rem1;
       nodes *rem2;
       l.size=0;
       l.start = NULL;

       
       FILE *file;
       file=fopen("tableKo.txt", "r");
       while (fscanf(file,"%c%d\n",&a,&b)>0){
            size++;
            }

            
       lii=(char*)malloc(sizeof(char)*size);
       w=(int*)malloc(sizeof(int)*size);
       size=0; 
       fclose(file);
       file=fopen("tableKo.txt", "r");
       while (fscanf(file,"%c%d\n",&lii[size],&w[size])>0){
            size++;
            }            

       FIND = l.start;         
       for(ctr=0;ctr<size;ctr++){
                 if(l.size==0){
                      NEW=New(lii[ctr], w[ctr]);
                      NEW->next = NULL;
                      l.start = NEW;
                      FIND = NEW;
                      l.size++;    
                             }              
                 else{
                      NEW=New(lii[ctr], w[ctr]);                       
                      NEW->next = NULL;
                      FIND->next = NEW;
                      FIND = NEW;
                      l.size++;
                      }               
                               }

       //creating now the binary tree
       



       while(l.size!=1){
             if(l.size==2){
             FIND = l.start;
             NEED = l.start; //original
             NEW = New('*', FIND->weight+FIND->next->weight);
             LEFT = FIND;
             RIGHT = FIND->next;
             NEW->left = FIND;
             NEW->right = FIND->next;   
             ROOT = NEW;
                           }
             
             else{
             FIND = l.start;
             NEED = l.start; //original
             NEW = New('*', FIND->weight+FIND->next->weight);
             LEFT = FIND;
             RIGHT = FIND->next;      
             NEW->left = FIND;
             NEW->right = FIND->next;      
             l.start = FIND->next->next;
             FIND = l.start;
             ROOT = NEW;
             if(FIND->weight>NEW->weight){
                      NEW->next = l.start;
                      l.start = NEW;                          
                                          }
             else{
                  sorted=0;
                  while(sorted==0){
                        if(FIND->next==NULL){
                                       FIND->next = NEW;      
                                       sorted=1;
                                             }
                        if(FIND->weight<=NEW->weight && FIND->next->weight>NEW->weight){
                                       NEW->next = FIND->next;
                                       FIND->next = NEW;              
                                       sorted=1;
                                                     }
                         FIND = FIND->next;          
                                   }
                  }
             }l.size--;
             aw++;
                        }
       
       
       
       FIND = l.start;

       printf("\n");

       display(ROOT, 0);
       system("PAUSE");
       }

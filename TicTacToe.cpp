#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
/*Brought to you by ®©ola™*/
//Roen Ivan Ylagan EV1 LBYCP12
int main(){
       
       int p1[3][3];
       int comp[3][3];
       int x,y,choice;      //variable declaration
       int a,b;
       int f,g;
       srand (time(NULL));   

                for(f=0;f<3;f++){
                for(g=0;g<3;g++){
                                p1[f][g] = 8;
                                }
                                }
       printf("  0   1   2\n");
       printf("0 X   X   X  \n\n");
       printf("1 X   X   X  \n\n");
       printf("2 X   X   X  \n\n");
       printf("Play Tic Tac Toe\n");
       printf("You're the X, He's the O: Beat him\n");
       printf("Choose Coordinates Please type (Y X) coordinates respectively:\n");
       while(p1[0][0] != 5){
       
       if((p1[0][0] == 1 && p1[0][1] == 1 && p1[0][2] == 1) || (p1[1][0] == 1 && p1[1][1] == 1 && p1[1][2] == 1) || (p1[2][0] == 1 && p1[2][1] == 1 && p1[2][2] == 1) || (p1[0][0] == 1 && p1[1][0] == 1 && p1[2][0] == 1) || (p1[0][1] == 1 && p1[1][1] == 1 && p1[2][1] == 1) || (p1[0][2] == 1 && p1[1][2] == 1 && p1[2][2] == 1) || (p1[0][0] == 1 && p1[1][1] == 1 && p1[2][2] == 1) || (p1[0][2] == 1 && p1[1][1] == 1 && p1[2][0] == 1))
       {
        printf("You Win!");
        getch();
        exit(0);
       }
       if((p1[0][0] == 0 && p1[0][1] == 0 && p1[0][2] == 0) || (p1[1][0] == 0 && p1[1][1] == 0 && p1[1][2] == 0) || (p1[2][0] == 0 && p1[2][1] == 0 && p1[2][2] == 0) || (p1[0][0] == 0 && p1[1][0] == 0 && p1[2][0] == 0) || (p1[0][1] == 0 && p1[1][1] == 0 && p1[2][1] == 0) || (p1[0][2] == 0 && p1[1][2] == 0 && p1[2][2] == 0) || (p1[0][0] == 0 && p1[1][1] == 0 && p1[2][2] == 0) || (p1[0][2] == 0 && p1[1][1] == 0 && p1[2][0] == 0))
       {
        printf("The PC wins!");
        getch();
        exit(0);
       }
       else{
       printf("Your move: ");
       scanf("%d %d", &b, &a);      
       p1[b][a] = 1;
       
       y = rand() % 3;    //this will generate a number from 0 to 2 randomly
       x = rand() % 3;
       
       if((p1[0][0] != 8) &&(p1[0][1] != 8)&& (p1[0][2] != 8)&& (p1[1][0] != 8)&& (p1[1][1] != 8)&& (p1[1][2] != 8) && (p1[2][0] != 8) && (p1[2][1] != 8) && (p1[2][2] != 8)){ 
       goto compare;
       }       
       home:
       if(p1[y][x] == 8){
                   p1[y][x] = 0;
       }
       else if(p1[y][x] == 0 || p1[y][x] == 1){
       y = rand() % 3;     //this will generate a number from 0 to 2 randomly
       x = rand() % 3;
       goto home;
       }
       

}
                for(f=0;f<3;f++){
                for(g=0;g<3;g++){
                                 switch(p1[f][g]){
                                 case 1:
                                      printf("[x] ");
                                      break;
                                 case 0:
                                      printf("[o] ");
                                      break;
                                 case 8:
                                      printf("[ ] ");
                                      break;
                                }
                                }
                                printf("\n");
                                }

                                }//end of while

        compare:
        if((p1[0][0] == 1 && p1[0][1] == 1 && p1[0][2] == 1) || (p1[1][0] == 1 && p1[1][1] == 1 && p1[1][2] == 1) || (p1[2][0] == 1 && p1[2][1] == 1 && p1[2][2] == 1) || (p1[0][0] == 1 && p1[1][0] == 1 && p1[2][0] == 1) || (p1[0][1] == 1 && p1[1][1] == 1 && p1[2][1] == 1) || (p1[0][2] == 1 && p1[1][2] == 1 && p1[2][2] == 1) || (p1[0][0] == 1 && p1[1][1] == 1 && p1[2][2] == 1) || (p1[0][2] == 1 && p1[1][1] == 1 && p1[2][0] == 1))
       {
        printf("You Win!");
        getch();
        exit(0);
       }
       if((p1[0][0] == 0 && p1[0][1] == 0 && p1[0][2] == 0) || (p1[1][0] == 0 && p1[1][1] == 0 && p1[1][2] == 0) || (p1[2][0] == 0 && p1[2][1] == 0 && p1[2][2] == 0) || (p1[0][0] == 0 && p1[1][0] == 0 && p1[2][0] == 0) || (p1[0][1] == 0 && p1[1][1] == 0 && p1[2][1] == 0) || (p1[0][2] == 0 && p1[1][2] == 0 && p1[2][2] == 0) || (p1[0][0] == 0 && p1[1][1] == 0 && p1[2][2] == 0) || (p1[0][2] == 0 && p1[1][1] == 0 && p1[2][0] == 0))
       {
        printf("The PC wins!");
        getch();
        exit(0);
       }
       getch();                         
}//end of main

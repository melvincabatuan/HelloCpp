#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>



int makeRandom()
{
    int ran;
    
    srand ( time(NULL));
    ran = rand() % 3 + 1;
    return ran;
}

int initPlayer(char piece)
{
    if (piece=='P' || piece=='p')
        {
	return 1;
	}

    else if (piece=='R' || piece=='r')
        {
	return 2;
	}

    else if (piece=='S' || piece=='s')
        {
	return 3;
	}

    else
	{
	return 0;
	}
}


int choose (int com)
{
    if (com==3)
	{
	printf ("\n The Computer chooses Scissors!");
	}

    else if (com==2)
	{
	printf ("\n The Computer chooses Rock!");
	}

    else if (com==1)
	{
	printf ("\n The Computer chooses Paper!");
	}
 
    else
	{
	return 0;
	}
}

int compareMove(int c, int p)
{
    if ((c==3 && p==1) || (c==2 && p==3) || (c==1 && p==2))
    	{
	choose(c);
	printf ("\n You Lose! Computer Wins!");
	return 1;
	}

    else if ((c==3 && p==2) || (c==2 && p==1) || (c==1 && p==3))
    	{
	choose(c);
	printf ("\n You win!");
	return 2;
	}

    else if ((c==3 && p==3) || (c==2 && p==2) || (c==1 && p==1))
    	{
	choose(c);
	printf ("\n Game Draws!");
	return 3;
	}

    else
 	{
 	return 0;
	}
}




int main()
{
      int playerinint,result,ps,cs,computer;
      char player;
      
      srand ( time(NULL));
      
      ps=0;
      cs=0;
      
      do 
      {
           system ("cls");
           
           printf ("\n\t\t\t\t\t\t\t Score: Computer = %d", cs);
           printf ("\t\t\t\t\t\t\t\t        Player   = %d", ps);
           
           printf ("\n\n Choose your move? <(R)Rock (P)Paper (S)Scissor> : ");
           scanf ("%c", &player);
           
           playerinint = initPlayer(player);
           computer = makeRandom();
           
           result = compareMove(computer,playerinint);
           
           switch (result)
           {
                  case 1:
                         ps=ps;
                         cs++;
                         break;
                  case 2:
                         ps++;
                         cs=cs;
                         break;
                  case 3:
                         ps=ps;
                         cs=cs;
                         break;
           }
           
           getch();
                      
      } while ((ps+cs)<10);
}

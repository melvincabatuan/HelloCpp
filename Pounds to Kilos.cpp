#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


main()
{
      int start, pounds;
      float kilo;
      printf("Pounds            Kilos\n");
      for(start=10;start<260;start+=10)
      {
           pounds = start;
           kilo = pounds*.45359;
           printf("%3.2d               %3.2f\n", pounds, kilo);
           }
      getch();
      }

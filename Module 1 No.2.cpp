#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int largest(int num[]){
	
	int x=num[0],i;
	for(i=0;i<100;i++){
		if(x<num[i]){
			x=num[i];	
		}
	}
	printf("\n\nThe largest in the given set of numbers is %d",x);
}

int main(){
	
	int num[100],i;
	srand(time(NULL));
	for(i=0;i<100;i++){
		num[i]=rand()%1000+1;
		printf("%d ",num[i]);
	}
	largest(num);
}

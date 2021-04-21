#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float maxNum(){
	int x;
	int arr[1000];
	srand(time(NULL));
	for(int i = 0; i < 1000; i++){
		x = rand() % 1000;
		arr[i] = x;
	}
	x = arr[0];
	for(int i = 1; i < 1000; i++){
		if(x < arr[i]){
			x = arr[i];
		}
	}
	printf("Max element in array: %d", arr[0]);
	return 0;
}

int main(){
	maxNum();
}

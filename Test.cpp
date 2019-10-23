#include <stdio.h>

int main(){
	int n = 10;
	int count = 0;
	for (int i = 0; i < n; ++i) 
    	for (int j = 0; j < i; ++j) 
        		count++;
    printf("count = %d", count);
    return 0;
}	

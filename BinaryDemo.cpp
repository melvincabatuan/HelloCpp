#include <stdio.h>
#include <math.h>

int find(int data[], int length, int key) {
    int location = -1;       // initialize to not found
    int begin = 0;           // beginning of the index
    int end = length - 1;    // end of the index
    int mid = 0;
    
    int count = 0;

	while (begin < end) {
		count++;
	    mid = floor((begin + end)/2.0);
	    if (data[mid] < key)
	        begin = mid + 1;  // upper half of data 
	    else
	        end = mid;        // lower half of data 
	}
    // Update location if element is found; default location = -1 (not found)
    if (data[begin] == key) location = begin;
    
    printf("Looking for %d; count = %d; ", key, count);
	return location;
}


int main() {
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15};
    int numbersLength = sizeof(numbers)/sizeof(numbers[0]);
    int num;
	for(int i = 1; i <= 20; ++i){
		int n = find(numbers, numbersLength, i);
		if ((n >= 0) && (n < numbersLength)) {
			printf("Found at index: %d\n", n);
		} else {
			printf("Not Found\n");
		}
		printf("\n\n");		
	}
	return 0;
}

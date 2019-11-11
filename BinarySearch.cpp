#include <iostream>


int binarySearch(int arr[], int length, int x){
	int mid;
	int i = 0;
	int j = length - 1;
	while( i < j){
		mid = (i + j)/2;
		if( x > arr[mid]) 
			i = mid + 1;
		else
			j = mid; 
	}
	if (arr[i] == x)
		return i;
	else
		return -1; // not found
}


int main(){
	int input[] = {1,2,3,5,6,7,8,10,12,13,15,16,18,19,20,22};
	std::cout << binarySearch(input, 16, 19);
	return 0;
}

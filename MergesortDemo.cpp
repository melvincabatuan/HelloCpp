#include <iostream>

const int SIZE = 8;

void display(int arr[]){
	std::cout << std::endl;
	for (int i = 0; i < SIZE; ++i)
	std::cout << arr[i] << " ";
}

void merge(int arr[], int begin, int end, int mid);
void mergeSort(int arr[], int begin, int end)
{
    if (begin >= end){
		return;    	
    }
    int mid = (begin + end)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, end, mid);   
}

void merge(int arr[], int begin, int end, int mid)
{
    int lower = begin;
    int upper = mid + 1;
    
    int temp[SIZE];
    int index = begin;
    
    // 1. Copy the elements (in ascending order) to temp array
    while (lower <= mid && upper <= end) {
        if (arr[lower] < arr[upper]) {
            temp[index++] = arr[lower++];
        }
        else  {
            temp[index++] = arr[upper++];
        }
    }
    
    // 2. Copy remaining elements to the temp array
    while (lower <= mid) {
        temp[index++] = arr[lower++];
    }
    while (upper <= end) {
        temp[index++] = arr[upper++];
    }
    
    // 3. Finally, copy temp elements to the array
    for (int i = begin; i < index; i++)  {
        arr[i] = temp[i];
    }
}

int main(){
	//int arr[SIZE] = {8,7,6,5,4,3,2,1};
	//int arr[SIZE] = {1,2,3,4,5,6,7,8};
	//int arr[SIZE] = {5,7,6,8,4,3,2,1};
	int arr[SIZE] = {5,3,6,1,4,7,2,8};
	display(arr);
	mergeSort(arr, 0, SIZE-1);
	display(arr);
	return 0;
}

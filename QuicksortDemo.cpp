#include <iostream>

const int SIZE = 8;

void display(int arr[]){
	std::cout << std::endl;
	for (int i = 0; i < SIZE; ++i)
	std::cout << arr[i] << " ";
}

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quicksort(int arr[], int begin, int end){
	if (end <= begin){
		return;
	}
	bool isSwap = false;
	display(arr);
	int pivot = arr[begin];
	std::cout <<"\n\npivot = " << pivot << std::endl;
	int less  = begin + 1;
	int more  = end;
	while(less < more){
		isSwap = false;
		while(less <= more && arr[less] < pivot){
			std::cout<< "less = " << less << std::endl;
			less++;
		}
		while(more >= less && arr[more] > pivot) {
			std::cout<< "more = " << more << std::endl;
			more--;
		}
		if (less < more){
			std::cout<< "swapless = " << less << ", swapmore = " << more <<std::endl;
			swap(arr, less, more);
			display(arr);
			less++;
			more--;
			isSwap = true;
		}	
	}
	if (pivot > arr[more]){
		swap(arr, more, begin);
	}
	display(arr);
	quicksort(arr, begin, more-1);
	quicksort(arr, more+1, end);
}

int main(){
	int arr[SIZE] = {8,7,6,5,4,3,2,1};
	//int arr[SIZE] = {1,2,3,4,5,6,7,8};
	//int arr[SIZE] = {5,7,6,8,4,3,2,1};
	//int arr[SIZE] = {5,3,6,1,4,7,2,8};
	quicksort(arr, 0, SIZE-1);
	return 0;
}

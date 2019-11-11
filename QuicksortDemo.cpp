#include<iostream>

const  int SIZE = 9;

void swap(int arr[], int less, int more){
 	 int temp = arr[less];
	arr[less] = arr[more];
	arr[more] = temp;
}

void display(int arr[]){
	std::cout << std::endl;
	for (int i = 0; i < SIZE; ++i)
	  std::cout << arr[i] << " ";
}


void quicksort(int arr[], int begin, int end){
	// Guard* the base case 
	if(begin >= end)
		return; // Do Nothing
	int pivot = arr[begin];
	int less = begin + 1;
	int more = end;
	while(less < more){
		while(less <= more && arr[less] < pivot) less++;	
		while(more >= less && arr[more] > pivot) more--;
		if(less < more){
			std::cout << "swapless "<< less<< "; swapmore "<< more<< std::endl;
			swap(arr, less, more);
			display(arr);			
		}
	}
	if (pivot > arr[more]){
		swap(arr, begin, more);
		std::cout << "swapless "<< less<< "; swapmore "<< more<< std::endl;
		display(arr);
	}
    quicksort(arr, begin, more-1); //left
    quicksort(arr, more + 1, end); //right
}



int main(){
	int arr[SIZE] = {6, 7, 4, 3, 8, 1, 2, 5, 9};
	display(arr);
	quicksort(arr, 0, SIZE-1);
	display(arr);
	return 0;
} 

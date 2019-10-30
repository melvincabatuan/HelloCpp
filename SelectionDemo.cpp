#include <iostream>
#include <limits>

using namespace std;

void display(int arr[], int length, int pass);

void selectionSort(int arr[], int length){
	int i, j, min, minat;
	for(i = 0; i < (length-1); i++)
	{
		cout<<"This is pass # \t"<< i << "\n";
		min = arr[i]; // current minimum
		minat = i;    // index of minimum
		for(j = i+1;j < length; j++)
		{
			if(min > arr[j])
			{
				min = arr[j]; // update minimum
				minat = j;    // index of minimum
				
			}
		}
		// swap minimum and first element of the array
		int temp = arr[i];
		arr[i] = arr[minat];
		arr[minat]=temp;
		
		display(arr, length, i);
		cout<<"\n\n";
	}
	cout<<"On Exit # \t"<< i << "\n";
	display(arr, length, i);
	cout<<"\n\n";
}

void insertionSort(int arr[], int length){
	int i, j, key;
	display(arr, length, 0);
	cout<<"\n\n";
	for(j = 1; j < length; j++)
	{
		key = arr[j];
		for(i = j - 1; (i >= 0) && (key < arr[i]); i--)
		{
			arr[i+1] = arr[i];
		}
		arr[i+1] = key;
		display(arr, length, j);
		cout<<"\n\n";
	}
}

void bubbleSort(int arr[], int length){
	bool swapped = true;
	int i, j = 0;
	int tmp;
	while (swapped)
	{
		swapped = false;
		j++;
		for (i = 0; i < length - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}
		cout<<"This is pass # \t"<< j - 1 << "\n";
		display(arr, length, i - 1);
		cout<<"\n\n";
	}
	cout<<"\n\n";
}

void display(int arr[], int length, int pass){
		for (int i = 0; i < length; i++)
		{
			cout<<arr[i]<<" ";
			if (i == pass) cout<< "| ";
		}
}

int main ()
{
	int count;
	int arr[20] = {0};
	
	cout<<"How many elements do you want?[2-20]\n";
	cin>>count; 
	while(cin.fail() || count > 20 || count < 2) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid input, re-enter number of elements [2-20]:\n";
      	cin>>count;
    }
	
	cout<<"You chose " << count << " elements\n";
	cout<<"Enter the elements \n";
	for(int i = 0; i < count; ++i)
	{
		cin>> arr[i];
	}
	cout<<"Your elements are \n";
	for (int i = 0; i < count; ++i)
	{
		cout<<"Element #"<<i+1<<'\t'<<arr[i]<<endl;
	}
	cout<<"\n";
	
	bubbleSort(arr, count);
	// insertionSort(arr, count);
	// selectionSort(arr, count);
	
	int answer;
	cout<<"Do you want to continue(1 for Yes, 2 for No?)";
	cin>>answer;
	while(cin.fail() || !(answer == 1 || answer == 2)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid input, re-enter choice to continue (1 for Yes, 2 for No?)\n";
      	cin>>answer;
    }
    if(answer == 1) main();
	if(answer == 2) exit(1);
	return 0;
}

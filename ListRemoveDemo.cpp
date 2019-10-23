#include <iostream>

// Cobalt-mkc: 10/23/2019

using namespace std;

//====== Empty List =========/

/* list element definition  */
struct node     
{
	int item;         // data    
	node *next;       // pointer to next item 
};

node *head = NULL;    // list entry point (or front)
int count = 0;

//---------------------------//

/* Minimal operations */

void addFront(int value);
void addLast(int value);
void add(int index, int value);
bool empty();
void displayList();
int size();
//=========================//


/* Implementations */

void addFront(int value)
{
	// 1. Create a new node
	node *temp = new node;
	// 2. Assign data to new node
	temp->item = value;
	// 3. Set pointer to next
	if (empty())
	{
		temp->next = NULL;  // first item
	}
	else
	{
		temp->next = head;  // insert in front of head
	}
	// 4. Set new node as head (front)
	head = temp;
	// 5. Increment count
	++count;
	return;
}

void addLast(int value)
{
	// 1. Create a new node
	node *temp = new node;
	// 2. Assign data to new node
	temp->item = value;
	// 3. Set pointer to next as null
	temp->next = NULL;  
	if (empty())
	{
		head = temp;
	}
	else
	{   // 4. Find the end element and Set its pointer to the new node
		node *last = head;
		while (last->next != NULL){
			last = last->next;	
		}
		last->next = temp;	
	} 
	
	// 5. Increment count
	++count;
	return;
}

void add(int index, int value)
{
	// 0. Handle error (guard)
	if(index < 0 || index > count){
		cerr << "Index Out of Bounds";
		return;
	}	
	// 1. Create a new node
	node *temp = new node;
	// 2. Assign data to new node
	temp->item = value;	
	
	// 3. Insert at front
	if (index == 0)   
	{
		temp->next = head;
		head = temp;
	} 
	else 
	{
		// 4. Find node prior to insertion
		node *previous = head;
		for(int i = 0; i < index - 1; ++i){    
			previous = previous->next;
		}
		// 5. Set the new node pointer to next element 
		temp->next = previous->next;
		// 6. Set previous next pointer to new node 
		previous->next = temp;
	}
	// 7. Increment count
	++count;
	return;
}

void remove(int index)
{
	// 0. Handle error (guard)
	if(index < 0 || index > count - 1){
		cerr << "Index Out of Bounds";
		return;
	}
	// 1. Base Case: Delete at front
	if (index == 0)   
	{
		node *temp = head;
		head = head->next;
		delete temp;
	} 
	else 
	{
	// 2. Otherwise, find previous and rewire  
		node *previous = head;
		for(int i = 0; i < index - 1; ++i){    
			previous = previous->next;
		}
		node *temp = previous->next;
		previous->next = temp->next;
		delete temp;
	}
	--count;
}

void displayList(){
	node *current = head;
	while(current != NULL){
		cout << current->item <<" ";
		current = current->next;
	}
	cout << endl;	
}

bool empty(){
	return head == NULL;
}

int size(){
	return count;
}

int main(){
	for(int i = 1; i < 11; ++i){
		addLast(i);	
	}
	cout << "Original List: " << endl;
	displayList();
	cout << endl;
//	remove(-1);  // Index out of bounds
//	remove(10);  // Index out of bounds
	for(int i = 0; i < 6; ++i){
		remove(i);	
		displayList();
	}
	return 0;
}

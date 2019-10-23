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
void add(int value);
void add(int index, int value);
int get(int index);
void remove(int index);
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

void add(int value)
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
		cerr << "ERROR: Index Out of Bounds";
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
		cerr << "ERROR: Index Out of Bounds";
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

int get(int index)
{
	// 0. Handle error (guard)
	if(index < 0 || index > count - 1){
		cerr << "ERROR: Index Out of Bounds";
		return 1;
	}
	node *current = head;
	for(int i = 0; i < index; ++i){    
		current = current->next;
	}
	return current->item;
}

void set(int index, int value)
{
	// 0. Handle error (guard)
	if(index < 0 || index > count - 1){
		cerr << "ERROR: Index Out of Bounds";
		return;
	}
	// 1. find current node
	node *current = head;
	for(int i = 0; i < index; ++i){    
		current = current->next;
	}
	// 2. Set value of current node
	current->item = value;
}

void clear()
{
	if (empty()){
		cout << "Empty list";
		return;
	}
    node *current = head;
    node *temp;
	while (current != NULL)  
	{  
	    temp = current->next;  
	    free(current);  
	    current = temp;  
	}
	head = NULL;
	count = 0;
}

void displayList(){
	if (empty()){
		cerr << "ERROR: Empty list";
		return;
	}
	node *current = head;
	while(current != NULL){
		cout << current->item <<" ";
		current = current->next;
	}
	cout << endl;	
}

bool empty(){
	return (head == NULL);
}

int size(){
	return count;
}

int main(){
	for(int i = 0; i < 11; ++i){
		add(i);
	}
	displayList();
	cout << "size() = " << size() << endl;
	cout << "empty() = " << empty() << endl;
	clear();
	cout << "size() = " << size() << endl;
	cout << "empty() = " << empty() << endl;
    displayList();
	return 0;
}

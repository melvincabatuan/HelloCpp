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

void displayList(){
	node *current = head;
	while(current != NULL){
		cout << current->item << endl;
		current = current->next;
	}	
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
	cout << "List size = " << size() << endl;
	displayList();
	return 0;
}

#include <iostream>

using namespace std;

//====== Empty List =========/

/* list element definition  */
struct node     
{
	int item;         // data    
	node *next;       // pointer to next item 
};

node *head = NULL;    // list entry point (or front)

//---------------------------//

/* Minimal operations */

void addFront(int value);
bool empty();
void displayList();

//=========================//


/* Implementations */

void addFront(int value)
{
	// 1. Create a new node
	node *temp = new node;
	// 2. Assign data and pointer to new node
	temp->item = value;
	temp->next = NULL; 
	// 3. Handle if list is not empty
	if (!empty())
	{
		temp->next = head;  // insert in front of head
	}
	// 4. Set new node as head (front)
	head = temp;
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

int main(){
	for(int i = 1; i < 11; ++i){
		addFront(i);	
	}
	displayList();
	return 0;
}

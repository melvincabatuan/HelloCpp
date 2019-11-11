#include <iostream>

using namespace std;
//=======================================/
//            TREE STRUCTURE
//=======================================/
struct node
{
 int data; // data
 node *left; // left subtree
 node *right; // right subtree
};

node *root = NULL;
//=======================================/

node* createNode(int value);
bool empty(node *tree);
void printTree(node *tree);
int getRoot(node *tree);

//=======================================/

node* addNode(node *tree, int value){
	if(tree == NULL){
		return createNode(value);
	}
	if(value <= tree->data){
		tree->left = addNode(tree->left, value);
	} else {
		tree->right = addNode(tree->right , value);
	}
	return tree;
}



node* createNode(int value){
//	cout << "Node created ... " << endl;
	node* temp = new node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int getRoot(node *tree){  // value gusto ko
	return tree->data;
}

void printTree(node *tree){
	if (empty(tree)){
	//	cerr << "Tree is empty";
		return;
	} else {
		printTree(tree->left);
		cout << tree->data <<" ";
		printTree(tree->right);
	}
}


void printPost(node *tree){
 	if (empty(tree)){
	//	cerr << "Tree is empty";
		return;
	} else {
		printTree(tree->left);
		printTree(tree->right);
		cout << tree->data <<" ";
	}
}


bool empty(node *tree){
	return (tree == NULL);
}

int main(){
 node* root = createNode(3);
 printPost(root);
 cout << endl;
 for(int i = 0; i < 5; ++i){
 	if (i == 3) continue;
 	addNode(root, i);
 }
 printPost(root);
 return 0;
}

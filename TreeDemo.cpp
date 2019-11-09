#include <iostream>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

//node* root = NULL; 

bool empty(node* root){
	return root == NULL;
}

node* createNode(int value){
	node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
}

void postfix(node* root){
	if (root != NULL){
		postfix(root->left);
		postfix(root->right);
		cout << root->data <<" ";
	}
}

int main(){
	node* tree = createNode(5);
	tree->left = createNode(3);
	tree->left = createNode(7);
	cout << empty(tree)<<endl;
	postfix(tree);
	return 0;
}

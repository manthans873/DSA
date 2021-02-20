#include <stdio.h>
const int N = 100;
int arr[N];
int i = 1;
class Node{
	int data;
	class Node* left;
	class Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
friend class Tree;
};

class Tree{
	class Node* root;
public:
	Tree(){
		root = NULL;
	}
	class Node* insert(class Node* node,int x);
	void Insert(int x);
	bool search(class Node* node,int x);
	void Search(int x);
	int max(class Node* node);
	void Max();
	void Inorder();
	void inorder(class Node* node);
	void preorder(class Node* node);
	void pre();
};


class Node* Tree::insert(class Node* node,int x){
	if(node == NULL){
		node = new Node(x);
		return node;
	}
	else if(x < node->data){
		node->left = insert(node->left,x);
	}
	else{
		node->right = insert(node->right,x);
	}
	return node;
}
bool Tree::search(class Node* node,int x){
	if(node == NULL) return false;
	else if(node->data == x) return true;
	else if(x < node->data) return search(node->left,x);
	else return search(node->right,x); 
}
void Tree::Insert(int x){
	root = insert(root,x);  // update the root
}
void Tree::Search(int x){
	bool ifpresent = search(root,x);
	if(ifpresent) printf("%d is present in Tree\n",x);
	else printf("%d is Not Found\n",x);
}
int Tree::max(class Node* node){
	if(node == NULL){
		return -1; 
	}
	if(node->right == NULL) return node->data;
	return max(node->right);
}
void Tree::Max(){
	int val = max(root);
	if(val == -1) printf("Tree is Empty\n");
	else printf("%d is maximum value in tree\n",val);
}
void Tree::inorder(class Node* node){
	if(node == NULL) return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
void Tree::Inorder(){
	inorder(root);
	printf("\n");
}

void Tree::preorder(class Node* node){
	if(node == NULL) return;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}

void Tree::pre(){
	preorder(root);
}
int main(){
	class Tree tr;

	tr.Insert(20);
	tr.Insert(30);
	tr.Insert(100);
	tr.Insert(1001);
	tr.Insert(2);
	tr.Insert(1);
	tr.Insert(3);

	tr.Search(30);
	tr.Search(40);
	tr.Search(100);

	tr.Max();
	tr.Inorder();
	printf("\n\n");
	tr.pre();

	return 0;
}
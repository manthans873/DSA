#include <stdio.h>


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
public:
	class Node* root;

	Tree(){
		root = NULL;
	}
	Tree(int x){
		class Node* root = new Node(x);
	}
	void insert(int x);
	bool search(int x);
	void inorder(class Node* node);
	void print();
};
void Tree::insert(int x){
	if(root == NULL){
		class Node* root = new Node(x);
	}
	else{
		class Node* temp1 = root;
		class Node* temp2;
		int flag = 0;
		class Node* node = new Node(x);
		do{
			if(x > temp1->data) {
				temp2 = temp1;
				temp1 = temp1->right;
				flag = 1;
			}
			else if(x < temp1->data) {
				temp2 = temp1;
				temp1 = temp1->left;
				flag = 2;
			}
			else {
				temp1 = NULL;
				flag = 0;
			}
		}while(temp1 != NULL);
		if(flag == 1){
			temp2->right = node;
		}
		else if(flag == 2){
			temp2->left = node;
		}
		else{
			printf("can't insert Node with existing data\n");
		}
	}
}
void Tree::inorder(class Node* node){
	if(node == NULL){
		return;
	}
	else{
		inorder(node->left);
		printf(" %d ",node->data);
		inorder(node->right);
	}
}
void Tree::print(){
	inorder(root);
}

int main(){
	class Tree tr;
	int n = 10;
	int i,x;
	for(i=0;i<n;++i){
		scanf("%d",&x);
		tr.insert(x);
	}
	tr.print();

	return 0;
}
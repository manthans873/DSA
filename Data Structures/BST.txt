#include <iostream>
#include <string>
#include <cmath> //cmath for ceil and floor functions tan of an angle also
#include <algorithm>
#include <iomanip>//for setprecision//    fixed<<////setprecision(value upto you want to precise)<<variable name;////
#include <vector>
#include<numeric>
#include <set> // to work with sets
#include <cstdlib>
#include <map>
#include <stdio.h>// for bitwise operators
#include <stdlib.h>
#include <unordered_set>
#include <math.h>// for pow() function

using namespace std;
typedef long long ll;

struct BstNode{
	int data;
	BstNode *left;
	BstNode *right;
};
BstNode *root = nullptr;
// initially set root pointer to null
BstNode * getnewnode(int data){
	BstNode *newnode = new BstNode();
	newnode->data=data;
	newnode->left=newnode->right=nullptr;
	return newnode;
}
// using recursion
BstNode * insert(BstNode *root,int data){
	// basic condition
	if (root==nullptr){
		root=getnewnode(data);
	}
	else if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
bool search(BstNode *root,int data){
	if (root==nullptr) return false;
	else if (root->data==data) return true;
	else if (data<=root->data) return search(root->left,data);
	else return search(root->right,data);

}
// not need to initialise a temp variable as root is a local variable
// as we have to return integer
int find_min(BstNode *root){
	if (root==nullptr){
		return -1;
	}
	while(root->left!=nullptr){
		root=root->left;
	}
	return root->data;
}
int find_max(BstNode *root){
	if (root==nullptr){
		return -1;
	}
	while(root->right!=nullptr){
		root=root->right;
	}
	return root->data;
}
int findMinRecurse(BstNode *root){
	if (root==nullptr){
		return -1;
	}
	if (root->left==nullptr){
		return root->data;
	}
	return findMinRecurse(root->left);
}
int main(){
	BstNode *root=nullptr;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,100);

	int mn = findMinRecurse(root);
	int mx = find_max(root);
	cout<<mn<<" "<<mx<<"\n";

	return 0;
}
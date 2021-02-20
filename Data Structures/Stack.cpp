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
#define MAX 1000



// In stack push(), pop(), peek(), isEmpty() take O(1) time.
//stack can be implemented using array or linked list

// Using array


class Stack{
private:
	int a[MAX];
	int top;
public:
	// here stack is constructor (means whenever a class is called it autmatically initialises )
	Stack(){
		top=-1; //declare the value of top 
		//whenever we create a class top =-1
	}
	void push(int x){
		if (top==MAX-1){
			cout<<"Stack Overflow"<<"\n";
			return;
		}
		top++;
		a[top]=x;
	}
	void pop(){
		if (top==-1){
			cout<<"Stack underflow"<<"\n";
			return;
		}
		top--;
	}
	int peek(){
		return a[top];
	}
	bool isEmpty(){
		if (top==-1) return true;
		return false;
	}
	void print_stack(){
		for(int i=0;i<=top;++i){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
};

int main(){
	Stack s;
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	cout<<"Top element of stack is: "<<s.peek()<<"\n";
	s.print_stack();
	if (s.isEmpty()){
		cout<<"stack is now become empty"<<endl;
	}
	else cout<<"stack is not empty"<<"\n";

	return 0;
}
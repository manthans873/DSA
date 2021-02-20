#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> trivial(string s){
	int n = s.length();
	vector<int> prefix(n);
	for(int i=0; i<n; ++i){
		for(int k=0; k<=i; ++k){
			if(s.substr(0,k) == s.substr(i-(k-1),k)){
				// complexity of s.substr() is O(k) where k is len of the returned string 
				prefix[i]=k;
			}
		}
	}
	return prefix;
}
// trivial soln is good but it's complexity is 
// O(n*n*n) and O(n) space required	
vector<int> opt(string s){
	int n = s.length();
	vector<int> prefix(n);
	// initially all elements of vector is zero
	for(int i=1; i<n; ++i){
		int j = prefix[i-1];
		while(j>0 && s[i]!=s[j]){
			j=prefix[j-1];
		}
		if(s[i]==s[j]){
			prefix[i]=j+1;
		} 
	}
	return prefix;
}

int main(){
	string s="ababab";
	vector<int> pf = trivial(s);
	for(auto el:pf){
		printf("%d ",el);
	}
	printf("\n");
	return 0;
}
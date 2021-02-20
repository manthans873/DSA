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
#include <unordered_map>

typedef long long ll;
 
using namespace std;

int main() {
	unordered_map<int, int>umap;
	umap[12] = 144;
	umap[11] = 121;
	umap[2] = 4;
	umap[5] = 25;
	umap.insert({15, 225});
	int n;
	cin >> n;
	auto it = umap.find(n);
	if (it != umap.end()) {
		cout << it -> first << " " << it -> second << "\n";
	}
	// or 
	if (it != umap.end()) {
		cout << (*it).first << " " << (*it).second << "\n";
	}
	else {
		cout << "NOt present" << endl;
	}
	// for iterating over map 
	for(auto el: umap){
		cout << el.first << " " << el.second << "\n";
	}
	return 0;
}
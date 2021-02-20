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
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
// STL in C++
// sets in cpp

int main() {
	set<int> s = {1, 2, 3, 3, 2};
	s.insert(45);
	for (auto& x: s) {
		cout << x << " ";
	}
	cout << endl;
	auto pos = s.find(2);
	if (pos != s.end()) {
		cout << "Found" << "\n";
	}
	else {
		cout << "Not Found" << "\n";
	}
	for (auto it = pos; it != s.end(); ++it) {
		cout<< *it <<" ";
	}
	cout << endl;
	return 0;
}





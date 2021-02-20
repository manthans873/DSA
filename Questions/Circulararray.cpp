#include <iostream>
#include <string>
#include <cmath> //cmath for ceil and floor functions tan of an angle also
#include <algorithm>// for sorting 
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
#include <cstring>
#include <map>

using namespace std;
typedef long long int ll;

int main() {
	int a[]={1,2,3,4,5};
	int size = sizeof(a)/sizeof(a[0]);
	int it;
	scanf("%d",&it);
	for(int i=it; i<size+it; ++i){
		printf("%d ",a[i%size]);
	}

	return 0;
}
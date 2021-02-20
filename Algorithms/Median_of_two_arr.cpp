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

typedef long long ll;
 
using namespace std;

int main() {
	int a[]={1,3,5};
    int b[]={2,4,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    vector<int>finalarr;
    int i=0,j=0;
    while(i<n){
        while(a[i]>b[j] && j<m){
            finalarr.push_back(b[j]);
            j++;
        }
        finalarr.push_back(a[i]);
        i++;
    }
    if(j!=m){
        while(j<m){
            finalarr.push_back(b[j]);
            j++;
        }
    }
    if((n+m)%2==0) cout<<(finalarr[(n+m)/2]+finalarr[((n+m)/2)-1])/2.0<<"\n";
    else cout<<finalarr[(n+m)/2]<<"\n";
	return 0;
}
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

vector<ll> subarr(vector<ll>arr, ll n, ll s) {
    ll i = 0, j = 0;
    ll sum = arr[0];
    while (i < n && j < n) {
        if (s > sum) {
            j++;
            if (j >= n) return {-1};
            sum += arr[j];
        }
        else if (s < sum) {
            sum -= arr[i];
            i++;
        }
        else {
            return {i + 1, j + 1};
        }
    }
    return {-1};
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        ll n,s;
        cin >> n >> s;
        vector<ll>arr(n);
        vector<ll>ans;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        ans = subarr(arr, n, s);
        for (auto &u : ans) {
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}
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

typedef long long ll;
using namespace std;
// solution of the problem (https://www.codechef.com/COOK116B/problems/MYSARA)
const ll mod = 1e9+7;

ll solve(vector<ll> &v,ll n){
	ll ans=1;
	for(ll i = 0; i < n-1; ++i) {
		if((v[i+1]&v[i]) != v[i]) {
			return 0;
		}
	}
	ll cnt=0;
	for(ll i=0;i<n-1;++i){
		ll var = v[i];
		while(var){
			cnt += var&1;
			var=var>>1;
		}
	}
	for(ll i=0;i<cnt;++i){
		ans=(ans*2)%mod;
	}
	return ans;
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll>v(n);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans = solve(v,n);
		cout<<ans<<"\n";
	}
	return 0;
}
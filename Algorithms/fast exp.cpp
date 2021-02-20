#include <iostream>

using namespace std;
typedef long long ll;

ll mod= 1e9+7;

ll power(ll a, ll b){
	ll ans=1;
	a=a%mod;
	while(b>0){
		if(b&1){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;			//squaring the number
		b=b>>1;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		cout<<power(a,b)<<"\n";
	}
	return 0;
}

ll pwr(ll a,ll b){
    ll ans=1;
    ll base=a;
    while(b){
        if(b&1) ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}
 
ll C(ll a,ll b){
    ll ans=1;
    for(int i=0;i<b;i++){
        ans=ans*(a-i)%mod;
    }
    ll aa=1;
    for(int i=1;i<=b;i++){
        aa=aa*i%mod;
    }
    return ans*pwr(aa,mod-2)%mod;
}
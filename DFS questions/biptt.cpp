#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <map>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;
const ll IMAX = 1000000000000000000;
const ll IMIN = -100000000000000000;

const ll N = 1e5 + 2;
vector<ll> adj[N];
bool vis[N];
ll clr[N];
// prob link: https://codeforces.com/problemset/problem/862/B

void dfs(ll num, ll cl){
    vis[num] = true;
    clr[num] = cl;
    for(ll cld:adj[num]){
        if(!vis[cld]){
            dfs(cld,cl^1);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(clr,-1,sizeof(clr));
    ll n,x,y,ctr=0;
    cin>>n;
    for(ll i=1;i<n;++i){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    for(ll i=1;i<=n;++i){
        if(clr[i] == 0) ctr++;
    }
    cout<<ctr*(n-ctr) - (n-1);

    return 0;
}

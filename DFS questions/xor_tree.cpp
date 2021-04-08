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
int init[N];
int goal[N];
vector<int>bag;
// prob link: https://codeforces.com/problemset/problem/429/A

void dfs(int num,int curr,int nxt){     // curr for changing given number
    vis[num] = true;                    // next for changing nxt generation
    init[num] = (init[num]+curr)%2;
    if(goal[num] != init[num]){
        goal[num] = init[num];
        curr^=1;
        bag.push_back(num);
    }
    for(int cld:adj[num]){
        if(!vis[cld]){
            dfs(cld,nxt,curr);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        cin>>init[i];
    }
    for(int i=1;i<=n;++i){
        cin>>goal[i];
    }
    dfs(1,0,0);
    cout<<bag.size()<<"\n";
    for(int elm:bag) cout<<elm<<"\n";

    return 0;
}

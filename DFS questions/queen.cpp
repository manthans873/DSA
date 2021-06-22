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
const ll IMIN = -10000000000000000;
const int N = 10e5+1;
vector<int> adj[N];
vector<int>bag;
int vis[N];
int sign[N];
// prob link: https://codeforces.com/problemset/problem/1143/C


// The main idea is either one node is going to deleted or stay forever hence just check all nodes 
// store in a vector and print it in sorted order
void dfs(int num){
    if(sign[num] == 0) return;
    for(int cld:adj[num]){
        if(sign[cld] == 0) return;
    }
    bag.push_back(num);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        if(x == -1) continue;
        adj[x].push_back(i);
        sign[i] = y;
    }
    for(int i=1;i<=n;++i){
        dfs(i);
    }
    sort(bag.begin(),bag.end());
    if(bag.size() == 0) cout<<-1<<"\n";
    for(int elm:bag) cout<<elm<<" ";

    return 0;
}

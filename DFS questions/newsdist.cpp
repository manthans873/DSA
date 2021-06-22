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
const int N = 5 * 10e5 + 1;
vector<int> adj[N];
vector<int>temp;
int vis[N];
int dp[N];
// prob link: https://codeforces.com/problemset/problem/1167/C

void dfs(int num){
    vis[num] = 1;
    temp.push_back(num);
    for(int cld:adj[num]){
        if(!vis[cld]){
            dfs(cld);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n, m, sz, val;
    cin >> n >> m;
    vector<vector<int>>mat(m);
    for(int i=0;i<m;++i)
    {
        cin >> sz;
        for(int j=0;j<sz;++j){
            cin>>val;
            mat[i].push_back(val);
        }
        for(int j=0;j<sz-1;++j){
            adj[mat[i][j]].push_back(mat[i][j+1]);
            adj[mat[i][j+1]].push_back(mat[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            temp.clear();
            dfs(i);
            for(int nodes:temp){
                dp[nodes] = temp.size();
            }
        }
        cout<<dp[i]<<" ";
    }
    return 0;
}

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
using std::pair;
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
const int N = 51;
string adj[N];
int vis[N][N];
// prob link: https://codeforces.com/problemset/problem/1130/C
int n;
ll f(pair<int,int>a,pair<int,int>b){
    ll ans = 0;
    ans += (a.first - b.first)*(a.first - b.first);
    ans += (a.second - b.second)*(a.second - b.second);
    return ans;
}
bool isvalid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=n) return false;
    return true;
}
void dfs(int x,int y,vector<pair<int,int>>&vec){
    vis[x][y]=1;
    vec.push_back({x,y});
    if(isvalid(x+1,y) && !vis[x+1][y] && adj[x+1][y] == '0'){
        dfs(x+1,y,vec);
    }
    if(isvalid(x-1,y) && !vis[x-1][y] && adj[x-1][y] == '0'){
        dfs(x-1,y,vec);
    }
    if(isvalid(x,y+1) && !vis[x][y+1] && adj[x][y+1] == '0'){
        dfs(x,y+1,vec);
    }
    if(isvalid(x,y-1) && !vis[x][y-1] && adj[x][y-1] == '0'){
        dfs(x,y-1,vec);
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
    int x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    string s;
    vector<pair<int,int>>start;
    vector<pair<int,int>>stop;
    for(int i=0;i<n;++i){
        cin>>s;
        adj[i] = s;
    }
    dfs(x1-1,y1-1,start);
    dfs(x2-1,y2-1,stop);
    ll ans = IMAX;
    for(int i=0;i<start.size();++i){
        for(int j=0;j<stop.size();++j){
            ans = min(ans,f(start[i],stop[j]));
        }
    }
    cout<<ans;
    return 0;
}

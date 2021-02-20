#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10001;
int timer=0;
int in[N],low[N];
bool vis[N];
vector<int> adj[N];

void dfs(int node,int par){
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(int cld:adj[node]){
        if(cld == par) continue;
        else if(!vis[cld]){
            // forward edge
            dfs(cld,node);
            if(low[cld]>in[node]){
                cout<<node<<" <-> "<<cld<<"\n";
            }
            low[node]=min(low[node],low[cld]);
        }
        else{
            // back edge between node and cld
            low[node]=min(low[node],in[cld]);
        }
    }
}
int main(){
    int n,e,x,y;
    cin>>n>>e;
    while(e--){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    
    return 0;
}

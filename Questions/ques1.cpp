#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=400000;
vector<int>adj[N];
bool vis[N];
int in[N],low[N];
int timer;
bool flag=true;
vector<pair<int,int>> edgs;

void is(int node,int par){
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(int cld:adj[node]){
        if(cld == par) continue;
        else if(!vis[cld]){
            is(cld,node);
            if(low[cld]>in[node]){
                flag=false;
                return;
            }
            low[node]=min(low[node],low[cld]);
            edgs.push_back({node,cld});
        }
        else{
            low[node]=min(low[node],low[cld]);
            if(in[node]>in[cld]){
                edgs.push_back({node,cld});
            }
        }
    }
}

int main(){
    int n,m,x,y;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    is(1,-1);
    if(!flag){
        cout<<0<<"\n";
    }
    else{
        printf("\n");
        for(auto pr:edgs){
            cout<<pr.first<<" "<<pr.second<<"\n";
        }
    }
    return 0;
}
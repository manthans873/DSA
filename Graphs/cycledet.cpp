//  cycle detection in undirected Graph

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent){
    vis[node]=true;
    for(int cld:adj[node]){
        if(!vis[cld]){
            if(dfs(cld,node)){
                return true;
            }
        }
        else if(cld!=parent){       //if cld is visited and it is not parent then return true
            return true;
        }
    }
    return false;
}
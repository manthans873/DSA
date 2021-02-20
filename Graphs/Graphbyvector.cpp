#include <iostream>
#include <vector>
using namespace std;

// undirected graph
void addEdge(vector<int> adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void printGraph(vector<int> adj[],int n){
    for(int i=0;i<n;++i){
        cout<<i<<" -> ";
        for(auto el:adj[i]){
            cout<<el<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n=4;
    vector<int>adj[n];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,2);
    printGraph(adj,n);
    return 0;
}
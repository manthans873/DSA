#include <iostream>
#include <list>
#include <cstring>
#include <queue>

using namespace std;
// graph using adjacency list
class Graph{
    int v;
    // pointer to the array containing adj list
    list<int> *adj;
public:
    // constructor(calls automatically)
    Graph(int v){
        this->v = v; // to avoid garbage values 
                    // as if we do v=v then it produces garbage values
        adj=new list<int>[v];

    } 
    void addEdge(int x,int y){
        adj[x].push_back(y);
    }
    void BFS(int s){
        bool *visited=new bool[v];
        queue<int>q;
        for(int i=0;i<v;++i){
            visited[i]=false;
        }
        visited[s]=true;
        q.push(s);
        while(!q.empty()){
            s=q.front();
            cout << s << " ";
            q.pop();
            // adj[x] is a linked list so we need an iterator to iterate through it
            for(auto it=adj[s].begin();it!=adj[s].end();++it){
                if(!visited[*it]){
                    // if vertex if not visited
                    // Then visit it and add it to queue
                    visited[*it]=true;
                    q.push(*it);
                }
            }
        }
    }
};

int main(){

    int v=4;
    Graph g(v);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);

    g.BFS(2);

    return 0;
}


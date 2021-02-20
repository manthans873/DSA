#include <iostream>
#include <list>

using namespace std;

class Graph{
    int v;
    // pointer to the array containing adj list
    list<int> *adj;
public:
    //constructor
    Graph(int v){
        this->v=v;
        adj=new list<int>[v];
        
    }
    void addEdge(int x,int y){
        adj[x].push_back(y);
    }
    // need to create help function
    // as this helf function call recursively
    // so visited 
    void help(int v,bool visited[]){
        visited[v]=true;
        cout<<v<<" ";
        for(auto itr=adj[v].begin();itr!=adj[v].end();++itr){
            if(!visited[*itr]){
                help(*itr,visited);  
            }
        }
    }
    void DFS(){
        bool *visited=new bool[v];
        for(int i=0;i<v;++i){
            visited[i]=false;
        }
        for(int i=0;i<v;++i){
            if(!visited[i]) help(i,visited);
        }
    }

};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3); 
    cout<<"dfs traversal of graph is: ";    
    g.DFS();

    return 0;
}
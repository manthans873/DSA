#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph{
    unordered_map<string, list<pair<string,int>> > l;
public:
    void addEdge(string x,string y,bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        // l[x] is a linked list -> we can push_back(make_pair(_,_))
        // if it is bidrectional 
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printAdjList(){
        for(auto el : l){
            cout<<el.first<<" -> ";
            for(auto val:el.second){
                cout<<val.first<<" "<<val.second<<", ";
            }
            cout<<"\n";
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printAdjList();

    return 0;
}
#include <iostream>
#include <list>

typedef long long ll;
using namespace std;

class Graph{
    int v;
    // list stl means doubly linked list
    list<int> *l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    // connecting two vertices
    void addEdge(int x, int y) {
    l[x].push_back(y);
    l[y].push_back(x);
    }
    // printing the connections of vertices
    void printAdjList() {
        for (int i = 0; i < v; ++i){
            cout << "Vertex "<<i<<" -> ";
            for(auto el:l[i]){
                cout<<el<<", ";
            }
            cout<<"\n";
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();

    return 0;
}
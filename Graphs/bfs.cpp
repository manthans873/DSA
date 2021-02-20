// link for question 
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/description/
/* finding minimum distance between 1 and n node*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

vector<int> adj[10001];
bool vis[10001];
int dist[10001];

void bfs(int node){
	queue<int>q;
	q.push(node);
	dist[node]=0;
	vis[node]=true;

	while(!q.empty()){
		int elm=q.front();
		for(int val:adj[elm]){
			if(!vis[val]){
				vis[val]=true;
				q.push(val);
				dist[val]=dist[elm]+1;
			}
		}
		q.pop();
	}

}
int main() {
	int t,n,m,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			adj[i].clear();		// vector can be cleared
			vis[i]=false;
		}
		while(m--){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bfs(1);
		for(int i=0;i<=n;++i){
			cout<<dist[i]<<" ";
		}
	}
	return 0;
}
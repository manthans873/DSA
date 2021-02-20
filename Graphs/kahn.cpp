#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int>adj[100];
vector<int>ans;
int in[100];

void kahn(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int elm = q.front();
        ans.push_back(elm);
        for(int cld:adj[elm]){
            in[cld]--;
            if(in[cld] == 0)
                q.push(cld);
        }
        q.pop();
    }
}
int main(){
    int n,m,x,y;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }
    kahn();
    return 0;
}
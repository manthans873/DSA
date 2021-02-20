
// In time and Out time of Nodes
int time = 1;
int intime[1000];
int outime[1000];
bool vis[1000];

void dfs(int node){
    vis[node]=true;
    intime[node]=time;
    time++;
    for(int cld:adj[node]){
        if(!vis[cld]){
            dfs(cld);
        }
    }
    outime[node]=time;
    time++;
}
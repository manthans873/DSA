#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
char grp[30][30];
bool vis[30][30];
int dist[30][30];
int n;

bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=n) return false;
    if(grp[x][y] == 'T' || vis[x][y]) return false;
    return true;
}
void bfs(int ix,int iy){
    queue<pair<int,int>>q;
    vis[ix][iy]=true;
    dist[ix][iy]=0;
    q.push({ix,iy});

    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(isValid(x-1,y)){
            vis[x-1][y]=true;
            q.push({x-1,y});
            dist[x-1][y] = dist[x][y]+1;
        }
        if(isValid(x+1,y)){
            vis[x+1][y]=true;
            q.push({x+1,y});
            dist[x+1][y] = dist[x][y]+1;
        }
        if(isValid(x,y-1)){
            vis[x][y-1]=true;
            q.push({x,y-1});
            dist[x][y-1] = dist[x][y]+1;
        }
        if(isValid(x,y+1)){
            vis[x][y+1]=true;
            q.push({x,y+1});
            dist[x][y+1] = dist[x][y]+1;
        }    
    }
}
int main(){
    for(int i=0;i<30;++i){
        for(int j=0;j<30;++j){
            vis[i][j]=false;
        }
    }
    int sx,sy,ex,ey;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>grp[i][j];
            if(grp[i][j] == 'S'){
                sx=i;
                sy=j;
            }
            else if(grp[i][j] == 'E'){
                ex=i;
                ey=j;
            }
        }
    }
    bfs(sx,sy);
    printf("%d\n",dist[ex][ey]);

    return 0;
}
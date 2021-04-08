#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <map>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;
const ll IMAX = 1000000000000000000;
const ll IMIN = -100000000000000000;

const int N = 1e4 + 1;
vector<int> adj[N];
bool vis[N];
int clr[N];
// prob link: https://codeforces.com/problemset/problem/902/B

void dfs(int num, int cl)
{
    vis[num] = true;
    clr[num] = cl;
    for (int cld : adj[num])
    {
        if (!vis[cld])
        {
            dfs(cld, cl);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, val, ans = 0;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        cin >> val;
        adj[val].push_back(i);  // to make directional graph
    }
    memset(clr, 0, sizeof(clr));
    for (int i = 1; i <= n; ++i)
    {
        cin >> val;
        if (clr[i] != val)
        {
            memset(vis,false,sizeof(vis));
            dfs(i, val);
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}

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
int steps;
// prob link: https://codeforces.com/problemset/problem/520/B

void dfs(int n,int m){
    steps++;
    if(n >= m){         // if n>m the only option is n--
        steps+=n-m-1;   // -1 for n==m as no steps are counted
        return;
    }
    if(m%2 == 0) dfs(n,m/2);
    else dfs(n,m+1);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    if(n>m){
        cout<<n-m;
        return 0;
    }
    dfs(n,m);
    cout<<steps;

    return 0;
}

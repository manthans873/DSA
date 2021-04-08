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

using std::cout;
using std::endl;  
using std::cin;
using std::string;
using std::vector;
using std::unordered_map;
using std::max;
using std::min;

typedef long long ll;
const ll IMAX = 1000000000000000000;
const ll IMIN = -100000000000000000;

const int M = 101;
vector<int>st;
// prob link: https://codeforces.com/problemset/problem/727/A    

/*
eg: dfs(2,162) -> dfs(2,81) -> dfs(2,8) -> dfs(2,4) -> dfs(2,2) -> st.pb(2) -> st.pb(4) -> st.pb(8) -> st.pb(81)
    These are the recursive calls
*/
bool dfs(int a, int b){      
    if(a > b) return false;
    if(a == b) return true;
    if(b%2 == 0 && dfs(a,b/2)){
        st.push_back(b/2);
        return true;
    }
    if((b-1)%10 == 0 && dfs(a,(b-1)/10)){
        st.push_back((b-1)/10);
        return true;
    }
    return false;
}       

int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int a,b;
    cin>>a>>b;
    if(dfs(a,b)){
        cout<<"YES\n";
        cout<<st.size()+1<<"\n";
        for(int elm:st){
            cout<<elm<<" ";
        }
        cout<<b<<"\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cmath> //cmath for ceil and floor functions tan of an angle also
#include <algorithm>
#include <iomanip>//for setprecision//    fixed<<////setprecision(value upto you want to precise)<<variable name;////
#include <vector>
#include<numeric>
#include <set> // to work with sets
#include <cstdlib>
#include <map>
#include <stdio.h>// for bitwise operators
#include <stdlib.h>
#include <unordered_set>
#include <math.h>// for pow() function
#include <cstring>
typedef long long ll;
 
using namespace std;

int dp[100][100];

int knapsack(int val[],int weight[],int w,int n){
    int ans=0;
    if(w==0 || n==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(weight[n-1]<=w){
        dp[n][w]=max(val[n-1]+knapsack(val,weight,w-weight[n-1],n-1),knapsack(val,weight,w,n-1));
        return dp[n][w];
    }
    else{
        dp[n][w]=knapsack(val,weight,w,n-1);
        return dp[n][w];
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    int values[]={6,10,12};
    int weight[]={1,2,3};
    cout<<knapsack(values,weight,5,3);
    return 0;
}
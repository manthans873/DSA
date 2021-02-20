#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getSubsets(vector<int> num){
    int size = num.size();
    int n = (1<<size);
    vector<vector<int> > allsubsets;
    for(int mask = 0; mask < n; ++mask){
        vector<int> subset; 
        for(int i = 0; i < size; ++i){
            if ((mask & (1<<i)) != 0){
                subset.push_back(num[i]);
            }
        }
        allsubsets.push_back(subset);
    }
    return allsubsets;
}
int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int> > v = getSubsets(arr);
    for(auto vec:v){
        for(auto el:vec){
            cout <<el << " ";
        }
        cout<<"\n";
    }
    return 0;
}
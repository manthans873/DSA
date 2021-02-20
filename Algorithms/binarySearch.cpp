#include <bits/stdc++.h>
using namespace std;


//recursive implementation 

int BinarySearch(int arr[],int l,int r,int x){
    if(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] == x) return mid;
        else if(x > arr[mid]) return BinarySearch(arr,mid+1,r,x);
        else return BinarySearch(arr,l,mid-1,x);
    }
    else{
        return -1;
    }
}
// iterative implementation
int bs_itr(int arr[],int l,int r,int x){
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] == x) return mid;
        else if(x>arr[mid]) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main(){
    int val;
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cin >> val;
    int ind = bs_itr(arr,0,n-1,val);
    if(ind ==-1) printf("Value is not present\n");
    else printf("value is present at index %d\n",ind);

    return 0;
}

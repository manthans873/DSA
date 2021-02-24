
// prob link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while(l + 1 < r){
            int mid = l + (r - l)/2;
            if(arr[mid] >= arr[mid - 1]){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if(arr[r] >= arr[l]) return r;
        else return l;
    }
};
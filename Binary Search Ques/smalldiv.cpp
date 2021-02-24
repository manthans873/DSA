
// prob link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int threshold){
        int summ = 0;
        for(int i = 0; i < nums.size(); ++i){
            summ += ceil(double(nums[i])/mid);
        }
        if(summ <= threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1000000;
        while(l + 1 < r){
            int mid = l + (r - l)/2;
            if(isValid(nums, mid, threshold)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        if(isValid(nums, l, threshold)) return l;
        return r;
    }
};
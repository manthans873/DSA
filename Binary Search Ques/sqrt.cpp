
// prob link: https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, r = x;
        while(l + 1 < r){
            int mid = l + (r - l)/2;        // due to int overflow
            if(mid <= x/mid){               // can't do  mid*mid <= x  due to integer overflow
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if(r <= x/r) return r;
        return l;
    }
};

// prob link: https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    int valid(vector<vector<int>>& matrix, int indx, int target){
        int c = matrix[0].size();
        return (matrix[indx/c][indx % c] <= target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int l = 0, h = r*c - 1;
        while(l + 1 < h){
            int mid = l + (h - l)/2;
            if(valid(matrix,mid,target)){
                l = mid;
            }
            else{
                h = mid;
            }
        }
        if(matrix[l/c][l%c] == target) return true;
        if(matrix[h/c][h%c] == target) return true;
        return false;
    }
};
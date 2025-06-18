class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(), cols=matrix[0].size();
        int left=0, right=rows*cols-1;
        while(left<=right){
            int mid=(left+right)/2;
            int row=mid/cols, col=mid % cols;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};

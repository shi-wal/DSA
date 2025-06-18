// TC: O(m + log n)
class Solution {
    bool binarySearch(vector<int> arr,int target,int left,int right){
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    } 
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(), cols=matrix[0].size(),row=0;
        for(int i=0;i<rows;i++){
            if(target<=matrix[i][cols-1]) {
                row=i;
                break;
            }
        }
        return binarySearch(matrix[row],target,0,cols-1);
    }
};

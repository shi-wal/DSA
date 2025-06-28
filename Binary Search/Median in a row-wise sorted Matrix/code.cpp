// TC: O(log(max−min)⋅m⋅logn)

class Solution {
    int upperBound(vector<int> arr, int x, int n){
        int left=0, right=n-1, ans=n;
        while(left<=right){
            int mid=(left+right)/2;
            if(x<arr[mid]) {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
    int blackbox(vector<vector<int>> &mat, int mid, int m, int n){
        int cnt=0;
        for(int i=0;i<m;i++){
            cnt+=upperBound(mat[i],mid,n);
        }
        return cnt;
    }
    
  public:
    int median(vector<vector<int>> &mat) {
        int m=mat.size(), n=mat[0].size();
        int req=n*m/2;
        int left=INT_MAX, right=INT_MIN;
        for(int i=0;i<m;i++){
            left=min(left,mat[i][0]);
            right=max(right,mat[i][n-1]);
        }
        while(left<=right){
            int mid=(left+right)/2;
            int smallerequals=blackbox(mat,mid,m,n);
            if(smallerequals<=req) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};

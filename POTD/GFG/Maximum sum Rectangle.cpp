// TC: Time Complexity: O(rows * cols^2)

class Solution {
    int kadane(vector<int> arr){
        int maxSum=INT_MIN, sum=0;
        for(int x:arr){
            sum+=x;
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int rows=mat.size(), cols=mat[0].size();
        int maxSum=INT_MIN;
        for(int cstart=0;cstart<cols;cstart++){
            vector<int> sum(rows,0);
            for(int cend=cstart;cend<cols;cend++){
                for(int r=0;r<rows;r++){
                    sum[r]+=mat[r][cend];
                }
                int currMaxsum=kadane(sum);
                maxSum=max(maxSum,currMaxsum);
            }
        }
        return maxSum;
    }
};

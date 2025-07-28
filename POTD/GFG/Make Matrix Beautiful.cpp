class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n=mat.size(), matSum=0, maxRsum=0, maxCsum=0;
        for(int i=0;i<n;i++){
            int rsum=0, csum=0;
            for(int j=0;j<n;j++){
                rsum+=mat[i][j];
                csum+=mat[j][i];
                matSum+=mat[i][j];
            }
            maxRsum=max(maxRsum,rsum);
            maxCsum=max(maxCsum,csum);
        }
        int maxSum=max(maxRsum,maxCsum);
        return maxSum*n-matSum;
    }
};

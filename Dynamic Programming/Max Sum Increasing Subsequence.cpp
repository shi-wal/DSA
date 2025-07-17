// Given an array of positive integers arr. Find the maximum sum subsequence of the given array such that 
// the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 
// TC: O(N^2)

class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++) dp[i]=arr[i]; // Initialine dp with arr elements
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j])
                    dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
        int maxSum=*max_element(dp.begin(),dp.end());
        return maxSum;
    }
};

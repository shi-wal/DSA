// Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum is equal to target. 
// The same number may be chosen from the array any number of times to make target.


class Solution {
    void solve(vector<int> &arr, int target, int ind, vector<int> &temp,
    vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp); return;
        }
        if(target<0) return;
        int n=arr.size();
        for(int j=ind;j<n;j++){
            temp.push_back(arr[j]);
            solve(arr,target-arr[j],j,temp,ans);
            temp.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,target,0,temp,ans);
        return ans;
    }
};

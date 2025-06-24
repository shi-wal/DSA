// TC: O(n*2^n), SC: O(2^n)
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
    void findSubsets(int index, int n, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        ans.push_back(temp);
        for(int i=index;i<n;i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            findSubsets(i+1,n,nums,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        findSubsets(0,n,nums,ans,temp);
        return ans;
    }
};

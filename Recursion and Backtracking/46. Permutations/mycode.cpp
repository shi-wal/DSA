// TC: O(N! * N), SC:O(N!) for ans + O(N) Recursion depth

class Solution {
    void solve(int ind, int n, vector<int>& nums, vector<vector<int>>& ans){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);   // choose
            solve(ind+1,n,nums,ans);   // explore
            swap(nums[ind],nums[i]);  // un-choose (backtrack)
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        solve(0,n,nums,ans);
        return ans;
    }
};

class Solution {
    void calculate(int i, int n, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(i==n){
            if(target==0) ans.push_back(temp);
            return;
        }        
        else if(target>=candidates[i]) {
            temp.push_back(candidates[i]);
            calculate(i,n,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }          
        calculate(i+1,n,candidates,target,ans,temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=candidates.size();
        calculate(0,n, candidates, target, ans, temp);
        return ans;
    }
};

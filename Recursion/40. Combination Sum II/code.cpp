//Understood

class Solution {
    void calculate(int ind, int n, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            calculate(i+1, n, candidates, target-candidates[i], ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> temp;
        calculate(0, n, candidates, target, ans, temp);
        return ans;
    }
};

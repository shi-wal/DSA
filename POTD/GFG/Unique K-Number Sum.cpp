class Solution {
    void findCombination(int sum,int k, int i,vector<vector<int>>& ans, vector<int>& arr){
        if(k==0 && sum==0){
            ans.push_back(arr);
            return;
        }
        if(k<=0 || sum<=0) return;
        for(int num=i;num<=9;num++){
            arr.push_back(num);
            findCombination(sum-num,k-1,num+1,ans,arr);
            arr.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        findCombination(n,k,1,ans,arr);
        return ans;
    }
};

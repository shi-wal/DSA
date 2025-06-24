// TC: O(2^n), SC: O(2^n)

class Solution {
    void calculateSum(int index, int sum, int n, vector<int>& arr, vector<int>& ans){
        if(index==n){
            ans.push_back(sum);
            return;
        }
        calculateSum(index+1, sum+arr[index], n, arr, ans);
        calculateSum(index+1, sum, n, arr, ans);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        calculateSum(0, 0, n, arr, ans);
        return ans;
    }
};

// TC: O(N*k), SC:O(N)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<bool> mark(n, false);
        for(int i=0; i<n; ++i) {
            if(nums[i]==key) {
                int left=max(0, i-k);
                int right=min(n-1, i+k);
                for(int j=left; j<=right; ++j) {
                    mark[j]=true;
                }
            }
        }
        vector<int> res;
        for(int i=0; i<n; ++i) {
            if(mark[i]) res.push_back(i);
        }
        return res;
    }
};

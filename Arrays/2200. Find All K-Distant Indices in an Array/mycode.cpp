// TC: O(NlogN), SC: O(N)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // Done by myself!
        set<int> st;
        vector<int> index;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key) index.push_back(i);
        }
        int i=0,j=0, m=index.size();
        while(i<n && j<m){
            if(i-index[j]>k) j++;
            if(j<m && abs(i-index[j])<=k){
                st.insert(i);
            }
            i++;
        }
        vector<int> res(st.begin(),st.end());
        return res;
    }
};

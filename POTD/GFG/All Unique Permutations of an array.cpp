// recursion
class Solution {
    void findPerm(vector<int>& arr,set<vector<int>>& st, int ind, int n){
        if(ind==n){
            st.insert(arr);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(arr[ind],arr[i]);
            findPerm(arr,st,ind+1,n);
            swap(arr[ind],arr[i]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        set<vector<int>> st;
        int n=arr.size();
        findPerm(arr,st,0,n);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// next-permutation
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        ans.push_back(arr);
        while(next_permutation(arr.begin(),arr.end())) ans.push_back(arr);
        return ans;
    }
};

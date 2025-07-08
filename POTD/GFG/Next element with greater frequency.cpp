class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num:arr) freq[num]++;
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && freq[st.top()]<=freq[arr[i]]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

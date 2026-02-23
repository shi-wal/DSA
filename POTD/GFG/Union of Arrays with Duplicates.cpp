class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;
        vector<int> res;
        int m=a.size(), n=b.size();
        for(int i=0;i<m;i++) st.insert(a[i]);
        for(int i=0;i<n;i++) st.insert(b[i]);
        for(int x:st) res.push_back(x);
        return res;
    }
};

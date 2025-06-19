// TC:O(N), SC:O(N)
class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st;
        int longest=1;
        for(int x:arr) {
            st.insert(x);
        }
        for(auto it:st){
        // Here we are checking LCS only for those who doesn't have prev cons. ele. hence it will reduce TC from N^2 to ~2N
            if(st.find(it-1)==st.end()){ 
                int x=it, cnt=1;
                while(st.find(x+1)!=st.end()){
                    x++; cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};

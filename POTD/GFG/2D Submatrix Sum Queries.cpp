// understood approach from chatgpt then done myself

class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> pref(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pref[i][j]=mat[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
        vector<int> ans;
        for(auto q:queries){
            int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            int val=pref[r2+1][c2+1]-pref[r1][c2+1]-pref[r2+1][c1]+pref[r1][c1];
            ans.push_back(val);
        }
        return ans;
    }
};

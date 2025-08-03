class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int q=opr.size(), m=mat.size(), n=mat[0].size();
        vector<vector<int>> diff(m,vector<int>(n,0));
        for(int i=0;i<q;i++){
            int val=opr[i][0];
            int r1=opr[i][1], c1=opr[i][2];
            int r2=opr[i][3], c2=opr[i][4];
            diff[r1][c1]+=val;
            if(c2+1<n) diff[r1][c2+1]-=val;
            if(r2+1<m) diff[r2+1][c1]-=val;
            if(c2+1<n && r2+1<m) diff[r2+1][c2+1]+=val;
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                diff[j][i]+=diff[j-1][i];
            }
        }
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                mat[j][k]+=diff[j][k];
            }
        }
        return mat;
    }
};

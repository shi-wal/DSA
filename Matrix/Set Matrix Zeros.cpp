class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        bool col0=false;
        int m=mat.size(), n=mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[i][0]==0)  col0=true;
            for(int j=1;j<n;j++){
                if(mat[i][j]==0){
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j]=0;
            }
        }
        if(mat[0][0]==0)
            for(int j=1;j<n;j++) mat[0][j]=0;
        if(col0) 
            for(int i=0;i<m;i++) mat[i][0]=0;
    }
};

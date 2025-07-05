// TC: O(N^2), SC: O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        int candidate=-1;
        for(int i=0;i<n;i++){
            bool Iknow=false;
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]==1){
                    Iknow=true;
                    break;
                }
            }
            if(!Iknow) {
                candidate=i;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(j!=candidate && mat[j][candidate]==0) return -1;
        }
        return candidate;
    }
};

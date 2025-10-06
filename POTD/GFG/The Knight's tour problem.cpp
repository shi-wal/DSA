class Solution {
    bool findTour(int i, int j, int n, int cnt, vector<vector<int>>& res){
        if(i<0 || i>=n || j<0 || j>=n || res[i][j]!=-1) return false;
        res[i][j]=cnt;
        if(cnt==n*n-1) return true;
        int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
        for(int k=0;k<8;k++){
            if(findTour(i+dx[k],j+dy[k],n,cnt+1,res)) return true;
        }
        res[i][j]=-1;
        return false;
    }
  public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> res(n,vector<int>(n,-1));
        if(findTour(0,0,n,0,res)) return res;
        return {{-1}};
    }
};

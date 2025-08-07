class Solution {
    int dfs(vector<vector<int>>& fruits, int row, int col, int moves, vector<vector<int>>& dp, const vector<pair<int,int>>& dir){
        int n=fruits.size();
        if(row==n-1 && col==n-1) return moves==0?0:INT_MAX;
        if(moves==0 || row==col) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        long long maxFruits=-1;
        for(auto [i,j]:dir){
            int newr=row+i, newc=col+j;
            if(newr>=0 && newr<n && newc>=0 && newc<n){
                int val=dfs(fruits,newr,newc,moves-1,dp,dir);
                if(val!=INT_MAX) maxFruits=max(maxFruits,(long long)val);
            }
        }
        return dp[row][col]=(maxFruits<0?INT_MAX:fruits[row][col]+maxFruits);
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int maxFruits=0;
        for(int i=0;i<n;i++) maxFruits+=fruits[i][i];
        vector<pair<int,int>> down_dir={{1,-1},{1,0},{1,1}};
        vector<vector<int>> dp(n,vector<int>(n,-1));
        maxFruits+=dfs(fruits,0,n-1,n-1,dp,down_dir);
        vector<pair<int,int>> right_dir={{-1,1},{0,1},{1,1}};
        for(auto& row:dp) fill(row.begin(),row.end(),-1);
        maxFruits+=dfs(fruits,n-1,0,n-1,dp,right_dir);
        return maxFruits;
    }
};

//Recursion
class Solution {
    int findCost(vector<int>& height, int i){
        if(i==0) return 0;
        int left=1e9, right=1e9;
        left=findCost(height,i-1)+ abs(height[i]-height[i-1]);
        if(i>1) right=findCost(height,i-2)+ abs(height[i]-height[i-2]);
        return min(left,right);
    }
  public:
    int minCost(vector<int>& height) {
        return findCost(height,height.size()-1);
    }
};

//Memoization
class Solution {
    int findCost(vector<int>& height, int i, vector<int>& dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int left=1e9, right=1e9;
        left=findCost(height,i-1,dp)+ abs(height[i]-height[i-1]);
        if(i>1) right=findCost(height,i-2,dp)+ abs(height[i]-height[i-2]);
        return dp[i]=min(left,right);
    }
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        return findCost(height,n-1,dp);
    }
};

//Tabulation
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> cost(n);
        cost[0]=0;
        for(int i=1;i<n;i++){
            int left=cost[i-1]+abs(height[i-1]-height[i]);
            int right=1e9;
            if(i>1) right=cost[i-2]+abs(height[i-2]-height[i]);
            cost[i]=min(left,right);
        }
        return cost[n-1];
    }
};

//Space-optimization
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        int prev=0, prev2=0;
        for(int i=1;i<n;i++){
            int left=prev+abs(height[i-1]-height[i]);
            int right=1e9;
            if(i>1) right=prev2+abs(height[i-2]-height[i]);
            int curr=min(left,right);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<int> prev(W+1), curr(W+1);
        // Base case initialization
        for(int w=wt[0];w<=W;w++) prev[w]=val[0];
        for(int i=1;i<n;i++){ // row
            for(int w=1;w<=W;w++){
                int nottake=prev[w];
                int take=(wt[i]<=w)?val[i]+prev[w-wt[i]]:INT_MIN;
                curr[w]=max(nottake,take);
            }
            prev=curr;
        }
        return prev[W];
    }
};

class Solution {
    int findCost(vector<int>& heights, vector<int>& cost, int x){
        int n=cost.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=cost[i]*abs(heights[i]-x);
        }
        return total;
    }
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // notes is in faroe islands
        int low=0;
        int high=1e4;
        int ans=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            int costxg=findCost(heights,cost,mid+1);
            int costx=findCost(heights,cost,mid);
            int costxl=findCost(heights,cost,mid-1);
            if(costxg>=costx && costx<=costxl) return costx;
            else if(costxg<costx) low=mid+1;
            else high=mid-1;
            ans=min(ans,costx);
        }
        return ans;
    }
};

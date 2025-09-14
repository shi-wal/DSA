class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();
        int totalgas=0, totalcost=0;
        int start=0, currgas=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
            currgas+=gas[i]-cost[i];
            if(currgas<0){
                start=i+1;
                currgas=0;
            }
        }
        if(totalgas<totalcost) return -1;
        return start;
    }
};

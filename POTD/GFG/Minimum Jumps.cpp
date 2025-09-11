class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int jumps=0;
        int currEnd=0, farthest=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            farthest=max(farthest,i+arr[i]);
            if(currEnd==i){
                jumps++;
                currEnd=farthest;
                if(currEnd>=n-1) return jumps;
            }
        }
        return -1;
    }
};

class Solution {
    bool calculateDistance(vector<int> stalls, int minDist, int k){
        int cows=1;
        int lastcow=stalls[0], n=stalls.size();
        for(int i=1;i<n;i++){
            if(stalls[i]-lastcow>=minDist) {
                cows++; 
                if(cows>=k) return true;
                lastcow=stalls[i];
            }
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        if(k>n) return -1;
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(calculateDistance(stalls,mid,k))
                low=mid+1;
            else high=mid-1;
        }
        //since low is pointing to most possible dist. and high is poiniting to not possible, 
        // hence according to binary search opposite polarity characteristic, 
        // we should return high because after BS, both will cross each other's polarity.
        return high; 
    }
};

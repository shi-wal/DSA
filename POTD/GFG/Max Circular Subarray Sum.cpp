class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int maxs=-1e9,mins=1e9,sum=0,curr=0,currneg=0;
        for(a:arr){
            sum+=a;
            curr=max(curr+a,a);
            maxs=max(maxs,curr);
            
            currneg=min(a,currneg+a);
            mins=min(currneg,mins);
        }
        if(sum==mins) return maxs;
        return max(maxs,sum-mins);

    }
};

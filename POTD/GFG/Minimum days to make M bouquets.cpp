class Solution {
    bool bouquetPossible(vector<int>& arr, int days, int k, int m){
        int n=arr.size(), bucket=0, i=0, flower=0;
        while(i<n){
            if(arr[i]<=days) {
                flower++;
                if(flower==k){
                    bucket++; 
                    flower=0;
                }
            }
            else flower=0;
            i++;
        }
        return bucket>=m;
    }
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n=arr.size();
        if(k*m>arr.size()) return -1;
        int high=-1, low=1e9;
        for(int x:arr){
            high=max(high,x);
            low=min(low,x);
        }
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(bouquetPossible(arr,mid,k,m)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};

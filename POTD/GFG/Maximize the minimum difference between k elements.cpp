class Solution {
    bool possible(vector<int>& arr, int diff, int k){
        int cnt=1, n=arr.size();
        int prev=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-prev>=diff){
                cnt++; prev=arr[i];
            }
            if(cnt==k) return true;
        }
        return false;
    }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int low=0, high=arr[n-1]-arr[0];
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(arr,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};

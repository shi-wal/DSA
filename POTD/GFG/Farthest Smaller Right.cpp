class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n=arr.size();
        vector<int> mintrack(n), ans(n,-1);
        mintrack[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            mintrack[i]=min(arr[i],mintrack[i+1]);
        for(int i=0;i<n;i++){
            int low=i+1, high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(mintrack[mid]<arr[i]){
                    ans[i]=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return ans;
    }
};

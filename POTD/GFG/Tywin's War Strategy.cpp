class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n=arr.size();
        int required=ceil((double)n/2), cnt=0;
        for(int i=0;i<n;i++){
            arr[i]%=k;
            if(arr[i]!=0) arr[i]=k-arr[i];
            else cnt++;
        }
        if(cnt>=required) return 0;
        sort(arr.begin(),arr.end());
        int soldiers=0;
        for(int i=0;i<required;i++)
            soldiers+=arr[i];
        return soldiers;
    }
};

class Solution {
    bool check(vector<int> &arr, int pages, int k){
        int student=1, n=arr.size(), sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]>pages){
                student++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        return student<=k;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int low=INT_MIN, high=0;
        for(int i=0;i<n;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(arr,mid,k)){
                high=mid-1;
                res=mid;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};

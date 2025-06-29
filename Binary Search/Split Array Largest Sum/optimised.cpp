// notes in diary
// Same logic for painter's problem and allocate books

class Solution {
    int countSplits(vector<int>& arr, int maxSum){
        int split=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=maxSum){
                sum+=arr[i];
            }
            else{
                split++;
                sum=arr[i];
            }
        }
        return split;
    }
    
  public:
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int splits=countSplits(arr,mid);
            if(splits>k) low=mid+1; // too many splits → need larger maxSum
            else high=mid-1; // valid with ≤ k splits → try smaller maxSum
        }
        return low;
    }
};

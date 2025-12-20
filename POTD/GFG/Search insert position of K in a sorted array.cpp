class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int n=arr.size();
        int left=0, right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==k) return mid;
            else if(arr[mid]<k) left=mid+1;
            else right=mid-1;
        }
        return right;
    }
};

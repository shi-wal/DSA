class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        if(arr[0]<=arr.back()) return 0;
        int left=0, right=arr.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]<=arr.back()) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};

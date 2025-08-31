// done myself in single run

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left=0, right=arr.size()-1;
        int maxWater=0;
        while(left<right){
            int water=min(arr[left],arr[right])*(right-left);
            maxWater=max(maxWater,water);
            arr[left]<=arr[right]?left++:right--;
        }
        return maxWater;
    }
};

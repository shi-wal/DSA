//TC: O(N), SC: O(N)

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        vector<int> suffixMax(n);
        suffixMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            suffixMax[i]=max(suffixMax[i+1],arr[i]);
      
        int leftmax=0, total=0;
        for(int i=0;i<n;i++){
            leftmax=max(leftmax,arr[i]);
            total+=min(leftmax,suffixMax[i])-arr[i];
        }
        return total;
    }
};

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0, xor_val=0, max_xor=0;
        while(i<n){
            if(i>=k) xor_val=xor_val^arr[i-k];
            xor_val=xor_val^arr[i];
            if(i>=k-1) max_xor=max(max_xor, xor_val);
            i++;
        }
        return max_xor;
    }
};

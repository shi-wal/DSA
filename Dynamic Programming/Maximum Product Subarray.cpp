class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int product=INT_MIN, left=1, right=1;
        for(int i=0;i<n;i++){
            left=left==0?1:left;  // if product becomes 0 then make it back to 1.
            right=right==0?1:right;
            left*=nums[i];
            right*=nums[n-i-1];
            product=max({product,left,right});
        }
        return product;
    }
};

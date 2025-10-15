// done myself with lil bit help of intuition only from video.
// https://youtu.be/GLsPRWxDuMA?si=e5mKgMiG3iSgUf1m
  
class Solution {
    bool findK(vector<int>& nums, int k){
        int n=nums.size();
        int req=k-1;
        if(req==0) return true;
        for(int i=k+1;i<n;i++){
            if(nums[i]>nums[i-1] && nums[i-k]>nums[i-k-1]) req--;
            else req=k-1;
            if(req==0) return true;
        }
        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int left=1, right=n/2;
        while(left<=right){
            int mid=(left+right)/2;
            if(findK(nums,mid)) left=mid+1;
            else right=mid-1;
        }
        return left-1;
    }
};

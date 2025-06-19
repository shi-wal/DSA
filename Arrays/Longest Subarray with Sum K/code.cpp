// find the length of the longest subarray where the sum of its elements is equal to the given value k. 
// this code works for non-negative no. also
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long,int> mp;
        int n=arr.size(), maxLen=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) maxLen=max(maxLen,i+1);
            long long rem=sum-k;
            if(mp.find(rem)!=mp.end())
                maxLen=max(maxLen,i-mp[rem]);
            if(mp.find(sum)==mp.end())
                mp[sum]=i;
        }
        return maxLen;
    }
};

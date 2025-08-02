/*
Step-by-Step Explanation:

Initialize variables:

sum = 0: to store the current prefix sum of transformed values.
ans = 0: to track the maximum subarray length found.
mp[0] = -1: base case for when the prefix sum becomes positive from the start.
Loop through the array (i = 0 to n-1):

Convert the element:

If arr[i] > k, treat it as +1
Otherwise, treat it as -1
Add it to the running sum.
If sum > 0:

The entire subarray from index 0 to i is valid.
So, set ans = i + 1.
If sum - 1 has been seen before:

This means there's a subarray ending at i with net positive sum.
Length of such subarray = i - mp[sum - 1]
Update ans with the maximum of current and this new length.
If sum is not already in the map:

Store mp[sum] = i to remember the first occurrence.
(We store the first index to ensure we get the longest possible subarray later.)
After loop ends:

Return ans as the final answer.
⏱️ Time and Space Complexity:

Time: O(n) — Single pass through the array.
Space: O(n) — For storing prefix sums in the hash map.
*/

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n=arr.size();
        int sum=0,maxLen=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=(arr[i]>k?1:-1);
            if(sum>0) maxLen=i+1;
            if(mp.find(sum-1)!=mp.end()) maxLen=max(maxLen,i-mp[sum-1]);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return maxLen;
    }
};

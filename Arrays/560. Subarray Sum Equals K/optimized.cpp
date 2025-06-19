// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;
        int sum=0, cnt=0;
        for(int num:nums){
            sum+=num;
            if(prefixCount.find(sum-k)!=prefixCount.end())
                cnt+=prefixCount[sum-k];
            prefixCount[sum]++;
        }
        return cnt;
    }
};

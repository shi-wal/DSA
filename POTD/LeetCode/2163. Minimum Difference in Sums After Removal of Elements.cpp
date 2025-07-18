class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int k=nums.size();
        vector<long long> suffix_sum(k+1,0);
        priority_queue<int,vector<int>,greater<int>> minheap;
        int n=k/3;
        long long sum=0;
        for(int i=k-1;i>=n;i--){
            minheap.push(nums[i]);
            sum+=nums[i];
            if(minheap.size()>n) {
                sum-=minheap.top();
                minheap.pop();
            }
            if(minheap.size()==n) {
                suffix_sum[i]=sum;
            }
        }
        priority_queue<int> maxheap;
        sum=0;
        long long min_diff=LLONG_MAX;
        for(int i=0;i<k-n;i++){
            maxheap.push(nums[i]);
            sum+=nums[i];
            if(maxheap.size()>n) {
                sum-=maxheap.top();
                maxheap.pop();
            }
            if(maxheap.size()==n)
                min_diff=min(min_diff,sum-suffix_sum[i+1]);
        }
        return min_diff;
    }
};

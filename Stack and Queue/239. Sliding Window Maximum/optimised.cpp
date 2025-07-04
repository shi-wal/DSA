// TC: O(2N)
// SC: O(N)+O(N-K)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> msw;
        deque<int> dq;
        for(int right=0;right<n;right++){
            if(!dq.empty() && dq.front()<=(right-k)){ //maintaining exact k window size
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(right>=k-1) msw.push_back(nums[dq.front()]);
        }
        return msw;
    }
};

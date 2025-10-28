class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<int> left(n,0), right(n,0);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
            right[n-i-1]=right[n-i]+nums[n-i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0) continue;
            if(left[i]==right[i]) cnt+=2;
            else if(abs(left[i]-right[i])==1) cnt+=1;
        }
        return cnt;
    }
};

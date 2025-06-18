// TC: O(N), SC:O(1)
class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, ele=-1, n=nums.size();
        for(int x:nums){
            if(cnt==0) ele=x;
            if(x==ele) cnt++;
            else cnt--;
        }
        if(cnt>0){
            cnt=0;
            for(int x:nums)
                if(ele==x) cnt++;
        }
       return cnt>n/2?ele:-1;  
    }
};

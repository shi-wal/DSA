#define mod 1000000007
class Solution {
    int calculatePow(int x, int y){
        if(x==0) return 0;
        if(y==0) return 1;
        if(y==1) return x;
        long long ans=1;
        if(y%2==0){
            ans=calculatePow(x,y/2);
            ans*=ans;
        }
        else{
            ans=calculatePow(x,y-1);
            ans*=x;
        }
        return ans%mod;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left=0, right=nums.size()-1;
        int cnt=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                cnt+=calculatePow(2,right-left);
                cnt%=mod;
                left++;
            }
            else   right--;
        }
        return cnt;
    }
};

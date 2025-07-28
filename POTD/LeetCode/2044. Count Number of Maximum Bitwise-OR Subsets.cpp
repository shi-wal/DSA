class Solution {
    void solve(vector<int>& nums,int index,int &cnt, int maxor, int curror){
        if(index==nums.size()){
            if(curror==maxor) cnt++;
            return;
        }
        solve(nums,index+1,cnt,maxor,curror | nums[index]);
        solve(nums,index+1,cnt,maxor,curror);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int cnt=0, maxor=0;
        for(int num:nums) maxor |= num;
        solve(nums,0,cnt,maxor,0);
        return cnt;
    }
};

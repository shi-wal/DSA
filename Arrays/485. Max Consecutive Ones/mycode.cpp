class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, maxcnt=0;
        for(int x:nums){
            if(x) cnt++;
            else {
                maxcnt=max(maxcnt,cnt);
                cnt=0;
            }
        }
        maxcnt=max(maxcnt,cnt);
        return maxcnt;
    }
};

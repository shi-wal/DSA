// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// TC: O(N), SC:O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0, ele1, ele2, n=nums.size();
        for(int x:nums){
            if(cnt1==0 && x!=ele2){
                cnt1=1; ele1=x;
            }
            else if(cnt2==0 && x!=ele1){
                cnt2=1; ele2=x;
            }
            else if(x==ele1) cnt1++;
            else if(x==ele2) cnt2++;
            else {
                cnt1--; cnt2--;
            }
        }
        cnt1=cnt2=0;
        int minlen=n/3;
        vector<int> res;
        for(int x:nums){
            if(ele1==x) 
                cnt1++;
            else if(ele2==x)
                cnt2++;
        }
        if(cnt1>minlen) res.push_back(ele1);
        if(cnt2>minlen) res.push_back(ele2);
        sort(res.begin(),res.end());
        return res;
    }
};

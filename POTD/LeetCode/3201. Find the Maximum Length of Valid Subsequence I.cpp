class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0, odd=0;
        int even_dp=0, odd_dp=0;
        for(int num:nums){
            if(num%2) {
                odd++;
                odd_dp=max(even_dp+1, odd_dp);  // longest subsequence ending in odd
            }
            else {
                even++;
                even_dp=max(odd_dp+1, even_dp);  // longest subsequence ending in even
            }
        }
        return max({even,odd,odd_dp,even_dp});
    }
};

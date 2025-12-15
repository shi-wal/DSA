class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=1, cnt=1;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            if(prices[i]==prices[i+1]+1) cnt++;
            else cnt=1;
            ans+=cnt;
        }
        return ans;
    }
};

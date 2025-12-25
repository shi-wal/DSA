class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int n=happiness.size();
        long long ans=0, cnt=0;
        for(int i=n-1;i>=n-k;i--){
            if((happiness[i]-cnt)>0)
                ans+=(happiness[i]-cnt);
            cnt++;
        }
        return ans;
    }
};

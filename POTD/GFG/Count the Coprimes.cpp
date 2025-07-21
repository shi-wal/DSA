const int MAX = 1e4;
class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxi+1, 0);
        for(int el : arr) freq[el]++;
        vector<int> mctr(maxi + 1, 0);
        for (int i=1; i <=maxi; ++i)
            for (int mul=1; i * mul <= maxi; ++mul)
                mctr[i] += freq[i * mul];
        vector<long> dp(maxi + 1, 0);
        for (int i = maxi; i >= 1; --i) {
            dp[i] = (long)mctr[i] * (mctr[i] - 1) / 2;
            for (int mul = 2; i * mul <= maxi; ++mul)
                dp[i] -= dp[i * mul];
        }
        return dp[1];
    }
};

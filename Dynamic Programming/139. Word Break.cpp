class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        int maxLen=0; // to know how far we want to go from current index to match dict word
        for(string str:wordDict){
            int k=str.length();
            maxLen=max(maxLen,k);
        }
        vector<bool> dp(n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=max(0,i-maxLen);j--){
                if(dp[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[i]=true;
                    break; // No need to check further prefixes
                }
            }
        }
        return dp[n];
    }
};

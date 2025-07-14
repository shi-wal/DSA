class Solution {
    bool check(long long num){
        if(num==1) return true;
        long long n=5;
        while(n<num) n*=5;
        if(n==num) return true;
        return false;
    }
    int findCuts(string &s, int index, vector<int> &dp){
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans=INT_MAX, i=0;
        long long temp=0; // temp is for current decimal value, i is for right to left index.
        for(int j=index;j>=0;j--){
            if(s[j]=='1'){
                temp+=pow(2,i);
                if(check(temp)==true){
                    int curr=findCuts(s,j-1,dp);
                    if(curr!=INT_MAX) ans=min(ans,1+curr);
                }
            }
            i++;
        }
        return dp[index]=ans;
    }
    
  public:
    int cuts(string s) {
        vector<int> dp(s.size(),-1);
        int ans=findCuts(s,s.size()-1,dp);
        return ans==INT_MAX?-1:ans;
    }
};

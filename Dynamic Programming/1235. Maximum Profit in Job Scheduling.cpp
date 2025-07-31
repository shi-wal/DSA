class Solution {
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1]<b[1];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> job;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end(),comp);
        vector<int> dp(n);
        dp[0]=job[0][2];
        for(int i=1;i<n;i++){
            int include=job[i][2];
            int latestNotConflict=-1;
            for(int j=i-1;j>=0;j--){
                if(job[j][1]<=job[i][0]){ // prev end <= curr start
                    latestNotConflict=j; break;
                }
            }
            if(latestNotConflict!=-1) include+=dp[latestNotConflict];
            dp[i]=max(include,dp[i-1]);
        }
        return dp[n-1];
    }
};

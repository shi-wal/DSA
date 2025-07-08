// Need revision (not understood)

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        // Sort by end time to simplify overlap checks
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // sort by end time
        });

        // Extract start times to use in binary search
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) endTimes[i] = events[i][1];

        // dp[i][j]: max value by considering first i events, using at most j selections
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            // Binary search to find the last event that ends before events[i-1][0] (start time)
            int last = upper_bound(endTimes.begin(), endTimes.begin() + i - 1, events[i - 1][0] - 1) - endTimes.begin();
            
            for (int j = 1; j <= k; ++j) {
                // Option 1: don't take current event
                dp[i][j] = dp[i - 1][j];

                // Option 2: take current event and add its value + best before
                dp[i][j] = max(dp[i][j], dp[last][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }
};

// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>> meet;
        int n=start.size();
        for(int i=0;i<n;i++){
            meet.push_back({end[i], start[i]});
        }
        sort(meet.begin(),meet.end());
        int cnt=1, freetime=meet[0][0];
        for(int i=1;i<n;i++){
            if(freetime<meet[i][1]) {
                cnt++;
                freetime=meet[i][0];
            }
        }
        return cnt;
    }
};

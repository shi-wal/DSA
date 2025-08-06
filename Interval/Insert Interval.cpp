class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        int n=intervals.size();
        vector<vector<int>> merged;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            merged.push_back(intervals[i++]);
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        merged.push_back(newInterval);
        while(i<n){
            merged.push_back(intervals[i++]);
        }
        return merged;
    }
};

class Solution {
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int remove=0;
        sort(intervals.begin(),intervals.end(),comp);
        int prev_end=intervals[0][1], n=intervals.size();
        for(int i=1;i<n;i++){
            if(prev_end>intervals[i][0]) remove++;
            else prev_end=intervals[i][1];
        }
        return remove;
    }
};

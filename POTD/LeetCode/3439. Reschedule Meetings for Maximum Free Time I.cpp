class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int maxduration=0, n=startTime.size();
        vector<int> freegap(1,startTime[0]);
        for(int i=1;i<n;i++)
            freegap.push_back(startTime[i]-endTime[i-1]);
        freegap.push_back(eventTime-endTime.back());
        int currentSum=0;
        for(int i=0;i<freegap.size();i++){
            currentSum+=freegap[i]-((i>=k+1)?freegap[i-(k+1)]:0); //sliding window of size k
            maxduration=max(maxduration,currentSum);
        }
        return maxduration;
    }
};

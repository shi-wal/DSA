class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int maxduration=0, n=startTime.size();
        vector<int> freegap(1,startTime[0]);
        for(int i=1;i<n;i++)
            freegap.push_back(startTime[i]-endTime[i-1]);
        freegap.push_back(eventTime-endTime.back());
        int m=freegap.size();
        vector<int> largestRight(m,0);
        for(int i=m-2;i>=0;i--){
            largestRight[i]=max(largestRight[i+1],freegap[i+1]);
        }
        vector<int> largestLeft(m,0);
        for(int i=2;i<m;i++){
            largestLeft[i]=max(largestLeft[i-1],freegap[i-2]);
        }
        for(int i=1;i<m;i++){
            int meetingtime=endTime[i-1]-startTime[i-1];
            if(meetingtime<=max(largestLeft[i],largestRight[i]))
                maxduration=max(maxduration,freegap[i-1]+freegap[i]+meetingtime);
            maxduration=max(maxduration,freegap[i-1]+freegap[i]);
        }
        return maxduration;
    }
};

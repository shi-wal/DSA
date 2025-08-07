class Solution {
  public:
    int minDifference(vector<string> &arr) {
        int n=arr.size();
        int minDiff=INT_MAX;
        vector<int> seconds;
        for(string s:arr){
            int hourInSec=stoi(s.substr(0,2))*3600;
            int minInSec=stoi(s.substr(3,2))*60;
            int sec=stoi(s.substr(6,2));
            seconds.push_back(hourInSec+minInSec+sec);
        }
        sort(seconds.begin(),seconds.end());
        for(int i=0;i<n;i++){
            int curr=seconds[i];
            int next=seconds[(i+1)%n];
            if(i==n-1) next+=24*3600;
            minDiff=min(minDiff,next-curr);
        }
        return minDiff;
    }
};

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int time=0, n=mices.size();
        for(int i=0;i<n;i++) time=max(abs(holes[i]-mices[i]),time);
        return time;  
    }
};

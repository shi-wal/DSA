class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int,int> freq;
        for(auto interval:intervals){
            freq[interval[0]]++;
            freq[interval[1]+1]--;
        }
        int current=0, prev=0;
        int maxNum=-1;
        for(auto it:freq){
            current+=it.second;
            if(current>=k) maxNum=it.first;
            else if(prev>=k) maxNum=it.first-1;
            prev=current;
        }
        return maxNum;
    }
};

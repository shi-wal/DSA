class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n=start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=1, j=0;
        int rooms=1, maxRoom=1;
        while(i<n && j<n){
            if(start[i]<end[j]) {
                rooms++; i++;
            }
            else {
                rooms--; j++;
            }
            maxRoom=max(maxRoom,rooms);
        }
        return maxRoom;
    }
};

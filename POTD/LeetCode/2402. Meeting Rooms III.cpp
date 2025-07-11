// coded myself after understanding from solution :)

class Solution {
    #define ll long long
    #define pli pair<long long,int> 
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> rooms;
        priority_queue<pli,vector<pli>,greater<pli>> occupied;
        vector<int> freq(n,0);
        for(int i=0;i<n;i++)
            rooms.push(i);
        int m=meetings.size();
        for(int i=0;i<m;i++){
            int endtime=meetings[i][1], room, start=meetings[i][0];
            while(!occupied.empty() && occupied.top().first<=start){
                rooms.push(occupied.top().second);
                occupied.pop();
            }  
            if(!rooms.empty()){
                room=rooms.top(); rooms.pop();
                occupied.push({endtime,room});
            }
            else{
                auto avail=occupied.top(); occupied.pop();
                long long et=avail.first;
                room=avail.second;
                ll duration = endtime-start;
                occupied.push({et+duration,room});
            } 
            freq[room]++;
        }
        int maxfreq=freq[0], index=0;
        for(int i=1;i<n;i++)
            if(maxfreq<freq[i]){
                index=i; maxfreq=freq[i];
            }
        return index;
    }
};

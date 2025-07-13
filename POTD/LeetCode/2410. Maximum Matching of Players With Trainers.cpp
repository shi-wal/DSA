// Note: This question is the same as 445: Assign Cookies.

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int m=players.size(), n=trainers.size(), i=0, j=0;
        while(i<m && j<n){
            if(players[i]<=trainers[j]) i++;
            j++;
        }
        return i;
    }
};

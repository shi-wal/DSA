// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        vector<vector<int>> jobs;
        int maxDeadline=-1;
        for(int i=0;i<n;i++){
            jobs.push_back({profit[i],deadline[i]});
            maxDeadline=max(maxDeadline,deadline[i]);
        }
        sort(jobs.rbegin(),jobs.rend());
        int countJobs=0, maxProfit=0;
        vector<int> slot(maxDeadline+1,-1);
        for(int i=0;i<n;i++){
            int dead=jobs[i][1];
            while(true){
                if(slot[dead] == -1){
                    slot[dead] = i;
                    maxProfit += jobs[i][0];
                    countJobs++;
                    break;
                } else {
                    dead--;
                    if(dead == 0) break;
                }
            }
        }
        return {countJobs,maxProfit};
    }
};

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        unordered_map<int,int> freq;
        for(int x:arr) freq[x]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:freq) pq.push({it.second,it.first});
        vector<int> ans;
        while(!pq.empty()){
            if(ans.size()==k) break;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

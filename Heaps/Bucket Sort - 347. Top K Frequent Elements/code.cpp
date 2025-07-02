class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int maxfreq=0;
        for(int x: nums) {
            freq[x]++;
            maxfreq=max(maxfreq,freq[x]);
        }
        vector<vector<int>> bucket(maxfreq+1);
        int cnt=0;
        for(const auto& pair:freq){
            int key=pair.first;
            bucket[freq[key]].push_back(key);
        }
        vector<int> res;
        for(int i=maxfreq; i>0 && cnt<k ;i--){
            while(!bucket[i].empty()) {
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                cnt++;
            }
        }
        return res;
    }
};

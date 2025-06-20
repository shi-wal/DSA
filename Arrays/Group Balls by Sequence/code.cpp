class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n=arr.size();
        if(n%k!=0) return false;
        
        map<int,int> mp;
        for(int x:arr) mp[x]++;
        
        for(auto item:mp){
            int num=item.first;
            int freq=item.second;
            if (freq == 0) continue;
            for (int i = 0; i < k; ++i) {
                if (mp[num + i] < freq) return false;
                mp[num + i] -= freq;
            }
        }
        return true;
    }
};

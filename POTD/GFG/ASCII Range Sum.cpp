class Solution {
  public:
    vector<int> asciirange(string& s) {
        unordered_map<char,pair<int,int>> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()) {
                mp[s[i]].first=i;
                mp[s[i]].second=-1;
            }
            else mp[s[i]].second=i;
        }
        vector<int> res;
        for(auto item:mp){
            int start=item.second.first;
            int last=item.second.second;
            if(last!=-1){
                int sum=0;
                for(int j=start+1;j<last;j++){
                    sum+=s[j];
                }
                if(sum!=0) res.push_back(sum);
            }
        }
        return res;
    }
};

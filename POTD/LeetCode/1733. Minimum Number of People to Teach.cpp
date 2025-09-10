class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
        int m=lang.size(), ans=m;
        unordered_map<int,unordered_set<int>> mp;
        int k=frnd.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<lang[i].size();j++){
                mp[lang[i][j]].insert(i+1);
            }
        }
        unordered_set<int> st;
        for(int i=0;i<k;i++){
            int user1=frnd[i][0], user2=frnd[i][1], flag=0;
            for(int j=0;j<lang[user1-1].size();j++){
                int l=lang[user1-1][j];
                if(mp[l].find(user2)!=mp[l].end()){
                    flag=1; break;
                }
            }
            if(!flag){
                st.insert(user1);
                st.insert(user2);
            }
        }
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(auto user:st){
                if(mp[i].find(user)==mp[i].end()) cnt++;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};

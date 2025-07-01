// TC:O(NlogN)

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n=a.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        pq.push({a[0]+b[0],{0,0}});
        st.insert({0,0});
        vector<int> ans;
        while(k--){
            auto top=pq.top(); pq.pop();
            int sum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            ans.push_back(sum);
            if(i+1<n && st.find({i+1,j})==st.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                st.insert({i+1,j});
            }
            if(j+1<n && st.find({i,j+1})==st.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
        }
        return ans;
    }
};

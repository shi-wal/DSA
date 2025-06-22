class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content=0;
        sort(s.rbegin(),s.rend());
        sort(g.rbegin(),g.rend());
        int n=s.size(), m=g.size(), i=0, j=0;
        while(i<n && j<m){
            if(s[i]>=g[j]){
                content++; i++;
            }
            j++;
        }
        return content;
    }
};

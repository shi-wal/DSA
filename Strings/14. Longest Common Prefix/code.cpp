class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string pref=strs[0];
        int m=pref.length();
        for(int i=1;i<n;i++){
            string curr=strs[i];
            while(m>curr.length() || pref!=curr.substr(0,m)){
                if(--m==0) return "";
                pref=pref.substr(0,m);
            }
        }
        return pref;
    }
};

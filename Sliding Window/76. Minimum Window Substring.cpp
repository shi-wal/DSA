class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c:t)
            mp[c]++;
        int cnt=0, m=t.length(), n=s.length();
        int left=0,right=0,minLen=INT_MAX, start=-1;
        string res="";
        while(right<n){
            if(mp[s[right]]>0) cnt++;
            mp[s[right]]--;
            while(cnt==m){
                if(minLen>(right-left+1)){
                    minLen=right-left+1;
                    start=left;
                }
                if(++mp[s[left]]>0) cnt--;
                left++;
            }
            right++;
        }
        return start==-1?"":s.substr(start,minLen);
    }
};

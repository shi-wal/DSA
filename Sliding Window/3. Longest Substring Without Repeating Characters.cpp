class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0, n=s.length();
        int left=0, right=0;
        unordered_map<char,int> mp;
        while(right<n){
            if(mp.find(s[right])!=mp.end()){
                // move left pointer to max of current or one past last index of current char
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            maxLen=max(maxLen,right-left+1);  
            right++;
        }
        return maxLen;
    }
};

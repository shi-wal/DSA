class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int left=0, right=0;
        int maxLen=0, maxFreq=0;
        vector<int> freq(26,0);
        while(right<n){
            freq[s[right]-'A']++;
            maxFreq=max(maxFreq,freq[s[right]-'A']);
            if((right-left+1)-maxFreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

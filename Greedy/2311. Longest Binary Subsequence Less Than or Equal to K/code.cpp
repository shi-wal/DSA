class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        long long val=0;
        int i=0;
        while(i<min(n,32)){
            if(s[n-i-1]=='1') val+=pow(2,i);
            if(val>k) break;
            i++;
        }
        int removed_count=0;
        while(i<n){
            if(s[n-i-1]=='1') removed_count++;
            i++;
        }
        return n-removed_count;
    }
};

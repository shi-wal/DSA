class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        unordered_map<char,int> roman;
        roman['I']=1; roman['V']=5; roman['X']=10; roman['L']=50;
        roman['C']=100; roman['D']=500; roman['M']=1000;
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(roman[s[i]]<roman[s[i+1]]) ans-=roman[s[i]];
            else ans+=roman[s[i]];
        }
        ans+=roman[s[n-1]];
        return ans;
    }
};

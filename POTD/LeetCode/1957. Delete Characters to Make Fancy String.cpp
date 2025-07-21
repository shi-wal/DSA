class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length(), duplicate=1;
        string ans ="";
        char c=s[0];
        ans+=s[0];
        for(int i=1;i<n;i++){
            if(s[i]!=c) {
                ans+=s[i];
                c=s[i];
                duplicate=1;
            }
            else{
                if(++duplicate<3) ans+=s[i];
            }
        }
        return ans;
    }
};

class Solution {
    vector<int> lpsArray(string &s){ // O(n)
        int n=s.length();
        vector<int> lps(n);
        int len=0;
        lps[0]=0;
        for(int i=1;i<n;){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0) len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
  public:
    int minChar(string &s) {
        string r=s;
        reverse(r.begin(),r.end());
        string concat=s+"$"+r;  // SC: O(N)
        vector<int> lps=lpsArray(concat);
        int n=s.length();
        return n-lps.back();
    }
};

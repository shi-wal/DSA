class Solution {
    vector<int> lpsArray(string& s){
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
    vector<int> search(string &pat, string &txt) {
        vector<int> index;
        vector<int> lps=lpsArray(pat);
        int i=0, j=0;
        int n=txt.length();
        int m=pat.length();
        while(i<n){
            if(txt[i]==pat[j]){
                i++; j++;
            }
            if(j==m){
                index.push_back(i-j);
                j=lps[j-1];
            }
            else if(i<n && txt[i]!=pat[j]){
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return index;
    }
};

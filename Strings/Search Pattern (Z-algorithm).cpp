class Solution {
  public:
    vector<int> search(string pat, string txt) {
        string concat=pat+"$"+txt;
        int n=concat.length();
        vector<int> z(n);
        int x=pat.length();
        int l=0,r=0;
        for(int i=1;i<n;++i){
            if(i<=r){
                z[i]=min(r-i+1,z[i-l]);
            }
            while(i+z[i]<n && concat[z[i]]==concat[i+z[i]]) z[i]++;
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        vector<int> ans;
        for(int i=x+1;i<n;i++){
            if(z[i]==x) ans.push_back(i-x);
        }
        return ans;
    }
};

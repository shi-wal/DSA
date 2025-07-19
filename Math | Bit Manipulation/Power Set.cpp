class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        int n=s.length();
        int x=pow(2,n);
        vector<string> res;
        for(int num=0;num<x;num++){
            string sub="";
            for(int i=0;i<n;i++){
                if(num & (1<<i)) sub+=s[i];
            }
            res.push_back(sub);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

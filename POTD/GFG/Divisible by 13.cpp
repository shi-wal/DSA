class Solution {
  public:
    bool divby13(string &s) {
        int num=0, n=s.length();
        for(int i=0;i<n;i++)
            num=(num*10+(s[i]-'0'))%13;
        return num==0;
    }
};

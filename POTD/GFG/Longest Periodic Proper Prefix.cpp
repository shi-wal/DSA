class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n=s.length();
        for(int i=n-1;i>=1;i--){
            bool valid=true;
            for(int k=i;k<n;k++){
                if(s[k]!=s[k%i]){
                    valid=false;
                    break;
                }
            }
            if(valid) return i;
        }
        return -1;
    }
};

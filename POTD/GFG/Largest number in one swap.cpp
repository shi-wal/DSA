class Solution {
  public:
    string largestSwap(string &s) {
        int n=s.length();
        for(int i=0;i<n-1;i++){
            int maxele=s[i], maxind=-1;
            for(int j=n-1;j>i;j--){
                if(s[j]>maxele){
                    maxele=s[j];
                    maxind=j;
                }
            }
            if(maxind!=-1) {
                swap(s[i],s[maxind]);
                return s;
            }
        }
        return s;
    }
};

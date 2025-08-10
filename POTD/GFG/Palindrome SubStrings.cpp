class Solution {
    int expand(string &s, int start, int end){
        int n=s.length(), cnt=0;
        while(start>=0 && end<n && s[start]==s[end]){
            if(start!=end) cnt++;
            start--; end++;
        }
        return cnt;
    }
  public:
    int countPS(string &s) {
        int cnt=0, n=s.length();
        for(int i=0;i<n;i++){
            cnt+=expand(s,i,i);
            cnt+=expand(s,i,i+1);
        }
        return cnt;
    }
};

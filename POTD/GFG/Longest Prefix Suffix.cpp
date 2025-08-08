class Solution {
  public:
    int getLPSLength(string &s) {
        int n=s.length();
        int i=0, j=1;
        int pos=j;
        while(j<n){
            if(s[i]==s[j]){
                i++; j++;
            }
            else{
                i=0; pos++;
                j=pos;
            }
        }
        return i;
    }
};

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int m=s1.length(), n=s2.length(), i=0, j=0;
        while(i<m && j<n){
            if(s1[i]==s2[j]) i++;
            j++;
        }
        return i==m;
    }
};

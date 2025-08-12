// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s 
// such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int i=0, j=0;
        int minLen=INT_MAX, start=-1;
        int n=s1.length(), m=s2.length();
        while(i<n){
            if(s1[i]==s2[j]) j++;
            if(j==m){
                int end=i;
                j--;
                while(j>=0){
                    if(s1[i]==s2[j]) j--;
                    i--;
                }
                i++; j++;
                if((end-i+1)<minLen){
                    minLen=end-i+1;
                    start=i;
                }
            }
            i++;
        }
        return start==-1?"":s1.substr(start,minLen);
    }
};

class Solution {
  public:
    bool isPalinSent(string &s) {
        string str="";
        for(char c:s){
            if(isalnum(c)) {
                if(isupper(c)) str+=(char)tolower(c);
                else str+=c;
            }
        }
        string rev=str;
        reverse(rev.begin(),rev.end());
        return str==rev;
    }
};


// using two pointer
class Solution {
  public:
    bool isPalinSent(string &s) {
        int left=0, n=s.length(), right=n-1;
        while(left<=right){
            while(left<n && !isalnum(s[left])) left++;
            while(right>=0 && !isalnum(s[right])) right--;
            if(left<=right){
                if(tolower(s[left])!=tolower(s[right])) return false;
                left++; right--;
            }
        }
        return true;
    }
};

// TC: O(N^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        string lps="";
        for(int i=1;i<n;i++){
            //for odd length palindrome
            int low=i, high=i;
            while(s[low]==s[high]){
                low--; high++;
                if(low==-1 || high==n) break;
            }
            string palindrome=s.substr(low+1,high-low-1);
            if(palindrome.length()>lps.length()) lps=palindrome;

            //for even length palindrome
            low=i-1, high=i;
            while(s[low]==s[high]){
                low--; high++;
                if(low==-1 || high==n) break;
            }
            palindrome=s.substr(low+1,high-low-1);
            if(palindrome.length()>lps.length()) lps=palindrome;
        }
        return lps;
    }
};

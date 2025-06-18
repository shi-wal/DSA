// Using Recursion & Backtracking
// https://www.youtube.com/watch?v=aZ0B1eWkSVU
class Solution {
    bool isPalindrome(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getAllParts(string s,vector<string> &parts, vector<vector<string>> &res){
        int n=s.size();
        if(n==0){
            res.push_back(parts);
            return;
        }
        for(int i=0;i<n;i++){
            string part=s.substr(0,i+1);
            if(isPalindrome(part)){
                parts.push_back(part);
                getAllParts(s.substr(i+1),parts,res);
                parts.pop_back();
            }
        }
    }
  public:
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> res;
        vector<string> parts;
        getAllParts(s,parts,res);
        return res;
    }
};

// Given a string s consisting of lowercase English letters and an integer k.
// Task is to remove exactly k characters from the string. The resulting string must be the largest possible in lexicographical  order, while maintain the relative order of the remaining characters.

// Very good & easy concept
class Solution {
  public:
    string maxSubseq(string& s, int k) {
        string str;
        for(char c: s){
            while(k>0 && !str.empty() && c>str.back()){
                str.pop_back();
                k--;
            }
            str.push_back(c);
        }
        str.resize(str.size()-k);
        return str;
    }
};

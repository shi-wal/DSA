// Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character, 
// such that the frequency of each distinct character in the string becomes same. Return true if it is possible; 
// otherwise, return false.

class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int> v(26,0);
        for(char c: s)  v[c-'a']++;
        vector<int> freq;
        for(int x:v){
            if(x) freq.push_back(x);
        }
        sort(freq.begin(),freq.end());
        int n=freq.size();
        if(freq.front()==freq.back()) return true;
        if(n>=2 && freq[0]==1 && freq[1]==freq.back()) return true;
        if(n>=2 && freq[n-1]==freq[n-2]+1 && freq[n-2]==freq[0]) return true;
        return false;
    }
};

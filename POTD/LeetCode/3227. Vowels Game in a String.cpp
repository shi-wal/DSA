class Solution {
    bool isVowel(char ch){
        string vowels="aeiou";
        return vowels.find(ch)!=string::npos;
    }
public:
    bool doesAliceWin(string s) {
        for(char c:s){
            if(isVowel(c)) return true;
        }
        return false;
    }
};

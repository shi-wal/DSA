class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;
        unordered_map<char,int> vowel,consonant;
        for(char c:word){
            if(!isalnum(c)) return false;
            else if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'|| c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
                vowel[c]++;
            else if(!isdigit(c)) consonant[c]++;
        }
        if(vowel.size()==0 || consonant.size()==0) return false;
        return true;
    }
};

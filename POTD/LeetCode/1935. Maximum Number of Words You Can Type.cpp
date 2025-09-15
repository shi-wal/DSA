class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool> mp;
        for(char c:brokenLetters) mp[c]=true;
        int words=0, n=text.length();
        bool full=true;
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                if(full) words++;
                full=true;
            }
            else{
                if(mp[text[i]]) full=false;
            }
        }
        if(full) words++;
        return words;
    }
};

// myself in single run

class Solution {
    bool isVowel(char ch){
        string vowels="aeiouAEIOU";
        return vowels.find(ch)!=string::npos;
    }
public:
    string sortVowels(string s) {
        vector<int> index;
        map<char,int> vowels;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                index.push_back(i);
                vowels[s[i]]++;
            }
        }
        if(index.empty()) return s;
        int m=index.size();
        int i=0;
        for(auto [c,freq]:vowels){
            while(freq--){
                s[index[i]]=c;
                i++;
            }
        }
        return s;
    }
};

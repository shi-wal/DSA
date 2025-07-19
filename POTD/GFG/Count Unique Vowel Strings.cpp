class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char,int> vowels;
        for(char c:s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')  vowels[c]++;
        }
        int product=1;
        int d=vowels.size();
        if(d==0) return 0;
        for(auto it:vowels){
            product*=it.second;
        }
        while(d!=0){
            product*=d;
            d--;
        }
        return product;
    }
};

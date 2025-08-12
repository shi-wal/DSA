class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string,vector<string>> mp;
        for(string str:arr){
            vector<int> freq(26,0);
            for(char c:str) freq[c-'a']++;
            string temp="";
            for(int i=0;i<26;i++){
                if(freq[i]>0){
                    temp.push_back('a'+i);
                    temp+=to_string(freq[i]); // If str="abbc", temp="a1b2c1"
                }
            }
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto& it:mp) ans.push_back(it.second);
        return ans;
    }
};

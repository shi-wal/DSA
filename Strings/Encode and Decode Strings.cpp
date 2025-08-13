class Solution {
  public:
    string encode(vector<string>& s) {
        string encoded="";
        for(string str:s){
            encoded+=str;
            encoded+='#';
        }
        return encoded;
    }

    vector<string> decode(string& s) {
        int n=s.length();
        vector<string> res;
        for(int i=0;i<n;){
            int start=i;
            while(s[i]!='#') i++;
            res.push_back(s.substr(start,i-start));
            i++;
        }
        return res;
    }
};

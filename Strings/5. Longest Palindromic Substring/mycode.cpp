class Solution {
    vector<int> expand(string &s, int start, int end){
        int n=s.length();
        while(start>=0 && end<n && s[start]==s[end]){
            start--; end++;
        }
        int len=end-start-1;// because both start and end moved extra step // my mistake --> end-start+1
        start=start+1; // already extra decremented //my mistake --> start not incremented by 1
        return {len,start};
    }
  public:
    string getLongestPal(string &s) {
        int n=s.length();
        int maxLen=0;
        string res="";
        for(int i=0;i<n;i++){
            vector<int> odd=expand(s,i,i);
            vector<int> even=expand(s,i,i+1);
            if(odd[0]>maxLen){
                maxLen=odd[0];
                res=s.substr(odd[1],maxLen);
            }
            if(even[0]>maxLen){
                maxLen=even[0];
                res=s.substr(even[1],maxLen);
            }
        }
        return res;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev=countAndSay(n-1);
        string res="";
        int m=prev.size();
        for(int i=0;i<m;i++){
            int cnt=1;
            while(i+1<m && prev[i]==prev[i+1]){
                i++; cnt++;
            }
            res+=to_string(cnt)+prev[i];
        }
        return res;
    }
};

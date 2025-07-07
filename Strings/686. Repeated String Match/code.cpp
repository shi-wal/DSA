// My code. TC: O((n - m) * m)
class Solution {
    bool checksubstring(string a, string b){
        int n=a.length();
        int m=b.length();
        for(int i=0;i<=n-m;i++){
            if(a.substr(i,m)==b) return true;
        }
        return false;
    }
    
  public:
    int repeatedStringMatch(string a, string b) {
        string temp=a;
        int ans=1;
        while(a.size()<b.size()){
            a+=temp;
            ans++;
        }
        if(checksubstring(a,b)) return ans;
        if(checksubstring(a+temp,b)) return ans+1;
        return -1;
    }
};

// using find function. TC: O((n - m) * m)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp=a;
        int ans=1;
        while(a.size()<b.size()){
            a+=temp;
            ans++;
        }
        if(a.find(b)!=string::npos) return ans;
        if((a+temp).find(b)!=string::npos) return ans+1;
        return -1;
    }
};

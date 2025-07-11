class Solution {
  public:
    int countConsec(int n) {
        if(n==2) return 1;
        int a=0, b=1,c;
        int ans=1;
        for(int i=3;i<=n;i++){
            c=a+b;
            ans=ans*2+c;
            a=b;
            b=c;
        }
        return ans;
    }
};

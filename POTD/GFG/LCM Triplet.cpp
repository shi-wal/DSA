class Solution {
  public:
    int lcmTriplets(int n) {
        if(n<=3) return n;
        int ans=0;
        if(n%2) ans=n*(n-1)*(n-2); // when n is odd
        else{
            if(n%6) ans=n*(n-1)*(n-3); // only div by 2 not 3
            else ans=(n-1)*(n-2)*(n-3);  // if n is divisible by 6 then it is divisible by both 2 & 3, hence (n-3) is not coprime
        }
        return ans;
    }
};

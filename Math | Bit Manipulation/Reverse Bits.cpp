class Solution {
  public:
    unsigned int reverseBits(unsigned int n) {
        unsigned int rev=0;
        while(n){
            rev=rev<<1;
            if(n&1) rev++;
            n=n>>1;
        }
        return rev;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        return b==0?a:getSum(a^b,(a&b)<<1);
    }
};
// so here a^b gives 1 if odd no. of 1 are available at particular position
// if even 1 at ith position then, a&b<<1 will give left shift ~ equiv. to carry.

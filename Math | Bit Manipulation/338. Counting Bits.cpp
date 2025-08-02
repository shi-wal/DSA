// Brute Force : TC:O(32*n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int cnt=0;
            for(int j=0;j<32;j++) if(i&(1<<j)) cnt++;
            ans[i]=cnt;
        }
        return ans;
    }
};

// The optimal approach for this problem uses DP and bit manipulation to achieve true O(n) time with lower constant overhead and no nested loop. 
// The key insight is:
// For each i, the number of set bits is 1 more than the number at i&(i−1), because i&(i−1) removes the least significant set bit from i.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++)
            ans[i]=ans[i & (i-1)]+1;
        return ans;
    }
};

// approach-1:

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1);
        steps[0]=1; steps[1]=1;
        for(int i=2;i<=n;i++){
            steps[i]=steps[i-1]+steps[i-2];
        }
        return steps[n];
    }
};


// approach-2:
class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int prev1=3, prev2=2, curr=0;
        for(int i=4;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};

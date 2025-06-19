class Solution {
public:
    int uniquePaths(int m, int n) {
        //Using Combinatorics
        int N=m+n-2; //Total directions
        int r=m-1; //NCr or NCc where c=n-1
        double res=1;
        for(int i=1;i<=r;i++)
            res=res*(N-r+i)/i; // N*N-1*N-2*......*N-r+2*N-r+1 / r!
        return int(res);
    }
};

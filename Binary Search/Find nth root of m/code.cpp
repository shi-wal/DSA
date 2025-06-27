// Time Complexity: O(n log m)
// Auxiliary Space: O(1)

class Solution {
    double solve(double num, int n){
        double ans=1.0;
        int i=1;
        while(i<=n){
            ans*=num; i++;
        }
        return ans;
    }
    
  public:
    int nthRoot(int n, int m) {
        double low=1, high=m, eps=1e-6;
        while((high-low)>eps){
            double mid=(low+high)/2.0;
            if(solve(mid,n)<m) low=mid;
            else high=mid;
        }
        int root=round(high);
        if(pow(root, n)==m)
            return root;
        else
            return -1; // No integer root exist
    }
};

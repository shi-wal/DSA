class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        int n=prices.size();
        sort(prices.begin(),prices.end());
        int minimum=0, maximum=0;
        int candy1=0, candy2=0;
        for(int i=0;i<n;i++){
            minimum+=prices[i];
            candy1+=(k+1);
            if(candy1>=n) break;
        }
        for(int i=n-1;i>=0;i--){
            maximum+=prices[i];
            candy2+=(k+1);
            if(candy2>=n) break;
        }
        return {minimum,maximum};
    }
};

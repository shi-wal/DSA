class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int left=numBottles;
        while(left>=numExchange){
            int drink=left/numExchange;
            ans+=drink;
            left=drink+left%numExchange;
        }
        return ans;
    }
};

// one line sol'n (from solutions)
class Solution {
public:
    int numWaterBottles(int b, int n) {
        return b + (b - 1) / (n - 1);
    }
};

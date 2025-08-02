/*
How totalcost+=min(fruits_to_swap[i],2*minEle) ??

Let's find the absolute cheapest fruit available in the entire problem. We'll call its cost min_val. We can use this fruit as a helper.
Move 1: Swap our fruit x with the helper min_val. The cost is min(x, min_val). Since min_val is the absolute minimum, this cost is just min_val.
Move 2: This leaves an unwanted min_val in our basket. We can now swap this min_val with the expensive fruit y from the other basket. The cost is min(y, min_val), which is again min_val.
The total cost for this two-step helper strategy is min_val + min_val = 2 * min_val.
*/

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> total_count;
        long long minEle=LLONG_MAX;
        for(int x:basket1) total_count[x]++;
        for(int x:basket2) total_count[x]++;
        for(auto const& [fruit, count]: total_count){
            if(count%2) return -1;
            minEle=min(minEle,(long long)fruit);
        }
        vector<long long> fruits_to_swap;
        map<int,int> freq1;
        for(int x:basket1) freq1[x]++;
        for(auto const& [fruit, count]: total_count){
            int diff=freq1[fruit]-(count/2);
            for(int i=0;i<abs(diff);i++) fruits_to_swap.push_back(fruit);
        }
        // sort(fruits_to_swap.begin(),fruits_to_swap.end());
        long long totalcost=0;
        int swaps_to_make=fruits_to_swap.size()/2;
        for(int i=0;i<swaps_to_make;i++) totalcost+=min(fruits_to_swap[i],2*minEle);
        return totalcost;
    }
};

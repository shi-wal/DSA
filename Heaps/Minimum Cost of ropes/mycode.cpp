class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int x:arr){
            minheap.push(x);
        }
        int cost=0;
        while(minheap.size()>1){
            int x=minheap.top(); minheap.pop();
            int y=minheap.top(); minheap.pop();
            cost+=x+y;
            minheap.push(x+y);
        }
        return cost;
    }
};

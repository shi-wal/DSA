class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        int opr=0;
        double sum=0;
        for(int x:arr) {
            sum+=(x*1.0);
            pq.push(x*1.0);
        }
        double half=sum/2;
        while(half<sum){
            double ele=pq.top()/2;
            pq.pop();
            sum-=ele;
            opr++;
            pq.push(ele);
        }
        return opr;
    }
};

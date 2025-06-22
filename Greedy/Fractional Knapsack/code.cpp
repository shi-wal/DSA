// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double maxValue=0.00;
        int n=val.size();
        vector<pair<double,int>> comp;
        for(int i=0;i<n;i++){
            comp.push_back({(double)val[i]/wt[i], i}); // approach to revise
        }
        sort(comp.rbegin(),comp.rend()); // approach to revise --> Descending order
        for(int i=0;i<n;i++){
            int index=comp[i].second;
            if(capacity>=wt[index]){
                capacity-=wt[index];
                maxValue+=val[index];
            }
            else{
                maxValue+=comp[i].first * capacity;
                break;
            }
        }
        return maxValue;
    }
};

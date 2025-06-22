// TC:O(N), SC:O(N) for ans.
class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> currency={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        for(int i=9;i>=0;i--){
            while(N>=currency[i]){
                N-=currency[i];
                ans.push_back(currency[i]);
            }
        }
        return ans;
    }
};

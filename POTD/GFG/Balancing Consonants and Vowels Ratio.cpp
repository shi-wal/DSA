class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        int n=arr.size();
        vector<pair<int,int>> freq(n);
        for(int i=0;i<n;i++){
            for(char c:arr[i]){
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                    freq[i].first++;
                else
                    freq[i].second++;
            }
        }
      
      // same approach as subarrays with sum k
        unordered_map<int,int> balanceMap;
        balanceMap[0]=1; // base case: when zero difference
        int result=0, vSum=0, cSum=0;
        for(auto [v,c]:freq){
            vSum+=v;
            cSum+=c;
            int balance=vSum-cSum;
            result+=balanceMap[balance];
            balanceMap[balance]++;
        }
        return result;
    }
};

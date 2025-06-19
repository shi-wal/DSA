class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int xr=0, cnt=0;
        unordered_map<int,int> mp;
        mp[xr]++; //mp[0]=1;
        for(int curr:arr){
            xr=xr^curr;
            int x=xr^k;
            cnt+=mp[x];
            mp[xr]++;
        }
        return cnt;
    }
};

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        int cnt=0, sum=0;
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;
        for(int num:arr){
            sum+=num;
            if(prefixCount.find(sum-k)!=prefixCount.end())
                cnt+=prefixCount[sum-k];
            prefixCount[sum]++;
        }
        return cnt;
    }
};

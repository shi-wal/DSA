class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int left=0, right=0;
        int n=arr.size();
        unordered_map<int,int> mp;
        int subarrays=0;
        while(right<n){
            mp[arr[right]]++;
            while(mp.size()>k){
                if(--mp[arr[left]]==0){
                    mp.erase(arr[left]);
                }
                left++;
            }
            subarrays+=(right-left+1);
            right++;
        }
        return subarrays;
    }
};

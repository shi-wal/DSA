class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int left=0, right=0;
        int n=arr.size();
        unordered_map<int,int> mp;
        int distinctCount=0, maxLen=0;
        while(right<n){
            if(mp.find(arr[right])!=mp.end())
                mp[arr[right]]++;
            else{
                while(distinctCount==2){
                    if(--mp[arr[left]]==0) {
                        mp.erase(arr[left]);
                        distinctCount--;
                    }
                    left++;
                }
                mp[arr[right]]++;
                distinctCount++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

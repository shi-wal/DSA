// did in 1 run myself :)

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int cnt=0, n=arr.size();
        int left=0, right=0, maxLen=0;
        while(right<n){
            if(arr[right]==0){
                if(cnt==k){
                    while(arr[left]!=0) left++;
                    left++;
                    cnt--;
                }
                cnt++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

class Solution {
    bool findAns(vector<int>& arr, int k, int maxSum){
        int sum=0;
        int cnt=1;
        for(int x:arr){
            sum+=x;
            if(sum>maxSum) {
                sum=x;
                cnt++;
            }
        }
        return cnt<=k;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        int left=0, right=0;
        for(int x:arr) {
            left=max(left,x);
            right+=x;
        }
        while(left<=right){
            int mid=(left+right)/2;
            if(findAns(arr,k,mid)) right=mid-1;
            else left=mid+1;
        }
        return right+1;
    }
};

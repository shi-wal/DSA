class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // notes not written
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        int res=INT_MAX, start=0;
        for(int i=0;i<n;i++){
            // We use upper_bound to find the first index where arr[j] > arr[i] + k. So, all values from index to n - 1 are greater than arr[i] + k and need to be reduced to arr[i] + k.
            int index=upper_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin(); 
            // This sets start as the total sum of elements smaller than arr[i], but only if arr[i] is a new distinct value (to avoid duplicate calculations). This cost is constant for that i, since we aren't modifying coins less than arr[i].
            if(i>0 && arr[i]!=arr[i-1])
                start=prefix[i-1];
            // prefix[n - 1] - prefix[index - 1]: sum of all values > arr[i] + k
            // (n - index) * (arr[i] + k): sum of what those values should become
            // So the second term computes the total cost to decrease all values > arr[i] + k to arr[i] + k
            // start is the sum of coins < arr[i] (cost for keeping them unchanged)
            // Then, res keeps track of the minimum such cost.
            res=min(res,start+(prefix[n-1]-prefix[index-1]) - (n-index)*(arr[i]+k));
        }
        return res;
    }
};

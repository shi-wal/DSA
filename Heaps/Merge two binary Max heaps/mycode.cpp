class Solution {
    void maxHeapify(vector<int> &arr, int index, int n){
        int left=2*index+1, right=2*index+2;
        int largest=index;
        if(left<n && arr[index]<arr[left]) largest=left;
        if(right<n && arr[largest]<arr[right]) largest=right;
        if(largest!=index) {
            swap(arr[largest],arr[index]);
            maxHeapify(arr,largest,n);
        }
    }
    
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int x:a) ans.push_back(x);
        for(int x:b) ans.push_back(x);
        for(int i=(n+m)/2;i>=0;i--)
            maxHeapify(ans,i,n+m);
        return ans;
    }
};

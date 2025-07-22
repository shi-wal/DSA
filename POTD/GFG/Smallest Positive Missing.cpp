// myself

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        unordered_map<int,int> freq;
        for(int num:arr) 
            if(num>0) freq[num]++;
        for(int i=1;i<=1e6;i++)
            if(freq.find(i)==freq.end()) return i;
        return -1;
    }
};


.// guided : TC=O(N), SC=O(1)

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n=arr.size();
        for(int i=0;i<n;++i){
            while(arr[i]>0 && arr[i]<=n && arr[arr[i]-1]!=arr[i]){
                swap(arr[i], arr[arr[i]-1]);
            }
        }
        for(int i=0;i<n;++i)
            if(arr[i]!=i+1)
                return i+1;
        return n+1;
    }
};

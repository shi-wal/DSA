//Need Revision
class Solution {
    bool isPossible(vector<int> &arr, int k, int w, int maxHeight){
        int n=arr.size();
        vector<int> water(n,0);
        for(int i=0;i<n;i++){
            if(i>0) water[i]=water[i-1];
            int currHeight=arr[i]+water[i];
            if(i>=w) currHeight-=water[i-w];
            if(currHeight<maxHeight){
                int add=maxHeight-currHeight;
                water[i]+=add;
                k-=add;
                if(k<0) return false;
            }
        }
        return true;
    }
    
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n=arr.size();
        int low=arr[0];
        for(int i=0;i<n;i++){
            low=min(low,arr[i]);
        }
        int high=low+k;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(arr,k,w,mid)){
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
};

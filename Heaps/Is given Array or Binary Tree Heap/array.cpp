// TC: O(n): Every node is visited once in a top-down recursive manner.

class Solution {
    bool isMaxOrder(int arr[], int i, int n){
        if(i>=n/2) return true; //leaf node
        bool leftpart=isMaxOrder(arr,2*i+1,n);
        bool rightpart=isMaxOrder(arr,2*i+2,n);
        return leftpart && rightpart && arr[i]>=arr[2*i+1] && 
            arr[i]>=arr[2*i+2];
    }
  public:
    bool isMaxHeap(int arr[], int n) {
        return isMaxOrder(arr,0,n);
    }
};

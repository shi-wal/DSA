// Time Complexity: O(k^2 * log k) , (k^2 elements inserted/popped from a heap of size k)
// Space Complexity: O(k) for the heap

using Element = pair<int, pair<int, int>>;
class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> merged;
        priority_queue<Element, vector<Element>, greater<Element>> minheap;
        for(int i=0;i<K;i++){
            minheap.push({arr[i][0],{i,0}});
        }
        while(!minheap.empty()){
            auto top=minheap.top(); minheap.pop();
            int x=top.first;
            merged.push_back(x);
            int i=top.second.first, j=top.second.second;
            if(j+1<K) minheap.push({arr[i][j+1],{i,j+1}});
        }
        return merged;
    }
};

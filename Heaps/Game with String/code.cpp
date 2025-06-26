class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        priority_queue<int> maxHeap;
        for(int f:freq){
            if(f > 0) maxHeap.push(f);
        }
        while(k-- && !maxHeap.empty()){
            int x=maxHeap.top(); maxHeap.pop();
            if(x>1) maxHeap.push(x-1);
        }
        int ans=0;
        while(!maxHeap.empty()){
            int top= maxHeap.top();
            maxHeap.pop();
            ans+=top * top;
        }
        return ans;
    }
};

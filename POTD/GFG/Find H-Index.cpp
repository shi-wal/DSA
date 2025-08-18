class Solution {
  public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int maxc=0;
        for(int i=0;i<n;i++){
            int c=min(citations[i],n-i);
            maxc=max(maxc,c);
        }
        return maxc;
    }
};

class Solution {
    int binarySearch(vector<int>& b, int element){
        int left=0, right=b.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(b[mid]<=element) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
    
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(),b.end());
        vector<int> res;
        for(int x:a) res.push_back(binarySearch(b,x));
        return res;
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans,curr;
        for(int x:arr){
            unordered_set<int> next= {x};
            for(int y:curr){
                next.insert(x|y);
            }
            ans.insert(next.begin(),next.end());
            curr=next;
        }
        return ans.size();
    }
};

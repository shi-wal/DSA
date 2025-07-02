using Element = pair<int,pair<int,int>>;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Element, vector<Element>, greater<Element>> minheap;
        int mini=INT_MAX, maxi=INT_MIN;
        int k=nums.size();
        for(int i=0;i<k;i++){
            int val=nums[i][0];
            minheap.push({val,{i,0}});
            mini=min(mini,val);
            maxi=max(maxi,val);
        }
        int start=mini, end=maxi;
        while(!minheap.empty()){
            auto top=minheap.top(); minheap.pop();
            mini=top.first;
            if(maxi-mini<end-start) {
                start=mini; end=maxi;
            }
            int i=top.second.first, j=top.second.second;
            if(j+1<nums[i].size()){
                int nextEle=nums[i][j+1];
                maxi=max(maxi,nextEle);
                minheap.push({nextEle,{i,j+1}});
            }
            else break; // One of the lists is exhausted
        }
        return {start,end};
    }
};

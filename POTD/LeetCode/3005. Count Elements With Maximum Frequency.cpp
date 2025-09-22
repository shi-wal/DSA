class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq=0;
        for(int x:nums){
            freq[x]++;
            maxFreq=max(maxFreq,freq[x]);
        }
        int ans=0;
        for(auto [i,f]:freq){
            if(f==maxFreq) ans+=f;
        }
        return ans;
    }
};

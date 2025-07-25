class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> freq;
        int sum=0, maxVal=INT_MIN;
        bool allNegative=true;
        for(int num:nums){
            if(num>=0) allNegative=false;
            if(num>maxVal) maxVal=num;
            if(num>0){
                if(freq.find(num)==freq.end()) sum+=num;
                freq[num]++;
            }    
        }
        return allNegative?maxVal:sum;
    }
};

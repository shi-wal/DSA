// Notes is in diary (Recusion section).
// TC:O(N^2), SC:O(N)

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1; //To find kth seq. in 0th based index
        string ans="";
        while(true){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};

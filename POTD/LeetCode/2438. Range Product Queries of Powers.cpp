class Solution {
    const int mod=1000000007;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i=0;i<32;i++)
            if(n & (1<<i)) powers.push_back(1<<i);
        vector<int> answer;
        for(auto query : queries){
            int start=query[0], end=query[1];
            int res=1;
            for(int i=start;i<=end;i++) res=(1LL*res*powers[i]) % mod;
            answer.push_back(res);
        }
        return answer;
    }
};

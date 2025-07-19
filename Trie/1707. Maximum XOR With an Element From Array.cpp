struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;  // getting the bit by checking if bit is set or not
            if(node->containsKey(1-bit)){
                maxNum=maxNum | (1<<i); // setting the ith bit.
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit); // ith bit will remain zero.
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q=queries.size();
        int n=nums.size();
        // O(nlogn)
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offlineQuery;
        for(int i=0;i<q;i++){
            offlineQuery.push_back({queries[i][1],{queries[i][0],i}});
        }
        // O(qlogq)
        sort(offlineQuery.begin(),offlineQuery.end());
        int ind=0;
        Trie trie;
        vector<int> answer(q,-1);
        // O(q*32 + n*32)  --> because while loop totally runs for n times only.
        for(int i=0;i<q;i++){
            int mi=offlineQuery[i].first;
            int xi=offlineQuery[i].second.first;
            int qi=offlineQuery[i].second.second;
            while(ind<n && nums[ind]<=mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0) answer[qi]=trie.getMax(xi);
        }
        return answer;
    }
};

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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int num:nums){
            trie.insert(num);
        }
        int maxNum=0;
        for(int num:nums){
            maxNum=max(maxNum, trie.getMax(num));
        }
        return maxNum;
    }
};

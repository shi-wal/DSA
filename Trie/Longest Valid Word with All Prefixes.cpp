struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool getEnd(){
        return flag;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string &word) {
        Node* node=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExists(string &word){
        bool flag=true;
        Node* node=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(node->getEnd()==false) return false; // prefix doesn't exist
            }
            else return false;
        }
        return true;
    }
    
};

class Solution {
    public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(auto &word:words){
            trie.insert(word);
        }
        string longest="";
        for(auto &word:words){
            if(trie.checkIfPrefixExists(word)){
                if(word.length()>longest.length() ||
                (word.length()==longest.length() && word<longest)) 
                    longest=word;
            }
        }
        return longest;
    }
};

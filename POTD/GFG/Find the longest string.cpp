// Given an array of strings arr[]. Find the longest string in arr[] such that every prefix of it is also present in the array arr[]. 

struct Node{
        Node* links[26];
        bool flag=false;
        
        bool containsKey(char ch){
            return links[ch-'a'];
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void put(char ch, Node* node){
            links[ch-'a']=node;
        }
        void setEnd(){
            flag=true;
        }
        bool isEnd(){
            return flag;
        }
};

class Trie{
    private: Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }
        bool checkIfPrefixExist(string word){
            bool fl=true;
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                    if(node->isEnd()==false) return false;
                }
                else return false;
            }
            return true;
        }
};    
    
class Solution {
    
  public:
    string longestString(vector<string> &words) {
        Trie trie;
        for(auto &it:words){
            trie.insert(it);
        }
        string longest="";
        for(auto &it:words){
            if(trie.checkIfPrefixExist(it)){
                if(it.length()>longest.length()) longest=it;
                else if(it.length()==longest.length() && it<longest) longest=it; 
            }
        }
        return longest;
    }
};

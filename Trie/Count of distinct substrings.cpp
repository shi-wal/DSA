/*You are required to complete this method */
struct Node{
    Node* links[26];
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    ~Node() {
        for(int i=0;i<26;++i) {
            delete links[i];  // safe even if nullptr
        }
    }
};

int countDistinctSubstring(string s) {
    int cnt=0;
    Node* root=new Node();
    int n=s.length();
    for(int i=0;i<n;i++){
        Node* node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j], new Node());
            }
            node=node->get(s[j]);
        }
    }
    delete root;
    return cnt+1;
}

// Manually using Sorting - Solved on 25-Oct-2024, 1st day of LC :) 

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        int j=0;
        for(int i=1;i<folder.size();i++){
            int n = res[j].length();
            if(folder[i].substr(0,n)== res[j] && folder[i][n]=='/'){
                continue;
            }
            else{
                res.push_back(folder[i]);
                j++;
            }
        }
        return res;
    }
};



// Using Trie

class Solution {
    struct Node{
        bool wordEnd=false;
        unordered_map<string,Node*> child;
    };

    void trieInsert(string &folder, Node* curr){
        int i=1, n=folder.size();
        while(i<n){
            string name="";
            while(i<n && folder[i]!='/') {
                name.push_back(folder[i]);
                i++;
            }
            if(curr->wordEnd) return;  // if already parent folder exists
            if(!curr->child.count(name)) curr->child[name]=new Node();
            curr=curr->child[name];
            i++;
        }
        curr->wordEnd=true;
        return;
    } 

    void searchTrie(Node* curr, vector<string> &res, string path){
        if(!curr) return;
        if(curr->wordEnd){
            path.pop_back(); 
            res.push_back(path);
            return;
        }
        for(auto& [name,child] : curr->child){
            searchTrie(child,res,path+name+'/');
        }
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Node* root=new Node();
        for(string &fld:folder)
            trieInsert(fld,root);
        vector<string> res;
        searchTrie(root,res,"/");
        return res;
    }
};

// GFG
class Solution {
    void getPath(Node* root, vector<vector<int>>& ans, vector<int>& path){
        if(!root) return;
        path.push_back(root->data);
        if(!root->left && !root->right) {
            ans.push_back(path);
        }
        else{
            if(root->left) getPath(root->left,ans,path);
            if(root->right) getPath(root->right,ans,path);
        }
        path.pop_back();  // Backtrack to original state
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>  ans;
        vector<int> path;
        getPath(root,ans,path);
        return ans;
    }
};

// LeetCode
class Solution {
    void getPath(TreeNode* root,vector<string>& ans, string& str){
        if(!root) return;
        int len=str.length();
        if(!str.empty()) str+="->";
        str=str+to_string(root->val);
        if(!root->left && !root->right) {
            ans.push_back(str);
        }
        else{
            if(root->left) getPath(root->left,ans,str);
            if(root->right) getPath(root->right,ans,str);
        }
        str.resize(len);  // Backtrack to original state
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str="";
        getPath(root,ans,str);
        return ans;
    }
};

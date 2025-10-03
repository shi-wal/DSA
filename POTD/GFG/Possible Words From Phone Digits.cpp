class Solution {
    void findWords(int ind,int n,string str, vector<int> &arr, vector<string>& ans, unordered_map<int,string>& mp){
        if(ind==n){
            ans.push_back(str);
            return;
        }
        if(arr[ind]<=1){
            findWords(ind+1,n,str,arr,ans,mp);
            return;
        }
        for(char ch:mp[arr[ind]]){
            findWords(ind+1,n,str+ch,arr,ans,mp);
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        unordered_map<int,string> mp;
        int n=arr.size();
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> ans;
        findWords(0,n,"",arr,ans,mp);
        return ans;
    }
};

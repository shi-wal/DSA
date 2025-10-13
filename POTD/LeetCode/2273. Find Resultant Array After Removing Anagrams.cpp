class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        string prev=words[0];
        ans.push_back(prev);
        sort(prev.begin(),prev.end());
        for(int i=1;i<n;i++){
            string curr=words[i];
            sort(curr.begin(),curr.end());
            if(prev!=curr){
                ans.push_back(words[i]);
                prev=curr;
            }
        }
        return ans;
    }
};

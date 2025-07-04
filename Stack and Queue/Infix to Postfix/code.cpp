class Solution {
  public:
    string infixToPostfix(string& s) {
        unordered_map<char,int> priority={
            {'^',3}, {'/',2},{'*',2},{'+',1},{'-',1}
        };
        int n=s.length();
        string ans;
        stack<char> st;
        for(char c:s){
            if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                ans+=c;
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else{
                while(!st.empty() && priority[c]<=priority[st.top()]){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        return ans;
    }
};

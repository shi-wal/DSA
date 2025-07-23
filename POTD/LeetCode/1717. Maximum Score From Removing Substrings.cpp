class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        bool flag=x>y?true:false;
        int score=0;
        for(char c:s){
            if(!st.empty()){
                if(flag){
                    if(c=='b' && st.top()=='a'){
                        st.pop();
                        score+=x;
                        continue;
                    }
                }
                else{
                    if(c=='a' && st.top()=='b'){
                        st.pop();
                        score+=y;
                        continue;
                    }
                }
            }
            st.push(c); 
        }
        string temp;
        while(!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(char c : temp) {
            if(!st.empty()){
                if(flag && c=='a' && st.top()=='b') {
                    score+=y;
                    st.pop();
                    continue;
                }
                if(!flag && c=='b' && st.top()=='a'){
                    score+=x;
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        return score;
    }
};

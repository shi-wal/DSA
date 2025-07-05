// Need to revise, didn't understand.

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int index=st.top(); st.pop();
                // i=next smaller element
                // st.top() =prev smaller element
                // if st is empty then range will be nse-pse-1=i-(-1)-1=i
                int range=st.empty()?i:i-st.top()-1; //max window size
                ans[range-1]=max(ans[range-1],arr[index]);
            }
            st.push(i);
        }
        // if stack is not empty
        while(!st.empty()){
            int index=st.top(); st.pop();
            // NSE will be n as i has reached to end
            // if st is empty then range will be nse-pse-1=n-(-1)-1=i
            int range=st.empty()?n:n-st.top()-1; //max window size
            ans[range-1]=max(ans[range-1],arr[index]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
};

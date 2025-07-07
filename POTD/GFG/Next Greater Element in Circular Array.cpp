// My Code
class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        vector<int> index;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(arr[i]);
            if(ans[i]==-1)  index.push_back(i);
        }
        for(int i:index){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
        }
        return ans;
    }
};


// ChatGPT
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse twice in reverse to simulate circular array
        for (int i = 2 * n - 1; i >= 0; --i) {
            int actualIndex = i % n;
            while (!st.empty() && st.top() <= arr[actualIndex]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    ans[actualIndex] = st.top();
                }
            }
            st.push(arr[actualIndex]);
        }

        return ans;
    }
};

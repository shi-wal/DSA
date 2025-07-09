// TC: O(N), SC: O(N)

class Solution {
    vector<int> findNSE(vector<int> &arr, int n){
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
           nse[i]=st.empty()?n:st.top();
           st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int> &arr, int n){
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
           pse[i]=st.empty()?-1:st.top();
           st.push(i);
        }
        return pse;
    }
  public:
    int sumSubMins(vector<int> &arr) {
        int total=0;
        int n=arr.size();
        vector<int> nse= findNSE(arr,n);
        vector<int> pse= findPSE(arr,n);
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total+=left*right*arr[i];
        }
        return total;
    }
};

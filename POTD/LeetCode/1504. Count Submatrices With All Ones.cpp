class Solution {
    int countMatrix(vector<int> arr){
        int n=arr.size();
        int ans=0;
        vector<int> sum(n);
        stack<int> st;
        for(int j=0;j<n;j++){
            while(!st.empty() && arr[st.top()]>=arr[j]) st.pop();
            if(!st.empty()){
                int prev=st.top();
                sum[j]=sum[prev]+arr[j]*(j-prev);
            }
            else{
                sum[j]=arr[j]*(j+1);
            }
            ans+=sum[j];
            st.push(j);
        }
        return ans;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> arr(m,vector<int>(n));
        for(int j=0;j<n;j++){
            arr[0][j]=mat[0][j];
            for(int i=1;i<m;i++){
                arr[i][j]=mat[i][j]==0?0:arr[i-1][j]+1;
            }
        }
        int total=0;
        for(int i=0;i<m;i++){
            total+=countMatrix(arr[i]);
        }
        return total;
    }
};

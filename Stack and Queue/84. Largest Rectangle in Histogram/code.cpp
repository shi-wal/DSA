class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0, n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int index=st.top(); st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,(nse-pse-1)*heights[index]);
            }
            st.push(i);
        }
        while(!st.empty()){
                int index=st.top(); st.pop();
                int nse=n; // No smaller bar to the right, so assume end
                int pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,(nse-pse-1)*heights[index]);
        }
        return maxArea;
    }
};

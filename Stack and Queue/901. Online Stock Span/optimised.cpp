class StockSpanner {
    stack<pair<int,int>> st;
    int ind=-1;
public:
    StockSpanner() {
        st= stack<pair<int,int>>(); ;
        ind=-1;
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans=ind-(st.empty()? -1:st.top().second);
        st.push({price,ind});
        return ans;
    }
};

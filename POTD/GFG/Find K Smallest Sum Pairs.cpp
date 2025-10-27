#define pii pair<int,int>
class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> ans;
        int m=arr1.size(), n=arr2.size();
        priority_queue<pair<int,pii>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=arr1[i]+arr2[j];
                if(pq.size()==k){
                    if(sum<pq.top().first){
                        pq.pop();
                        pq.push({sum,{arr1[i],arr2[j]}});
                    }
                    else break;
                }
                else pq.push({sum,{arr1[i],arr2[j]}});
            }
        }
        while(!pq.empty()){
            auto ele=pq.top().second;
            pq.pop();
            ans.push_back({ele.first,ele.second});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// optimized:

#define pii pair<int,int>

class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> ans;
        int m = arr1.size(), n = arr2.size();
        if (m == 0 || n == 0 || k == 0) return ans;

        using T = pair<int, pii>; // {sum, {i, j}}
        priority_queue<T, vector<T>, greater<T>> pq;

        // Push first element from each row (arr1[i] + arr2[0])
        for (int i = 0; i < min(m, k); i++)
            pq.push({arr1[i] + arr2[0], {i, 0}});

        while (k-- > 0 && !pq.empty()) {
            auto [sum, p] = pq.top(); pq.pop();
            int i = p.first, j = p.second;
            ans.push_back({arr1[i], arr2[j]});

            // Push next element from the same row (i, j+1)
            if (j + 1 < n)
                pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
        }

        return ans;
    }
};

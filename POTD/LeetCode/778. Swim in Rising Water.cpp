#define pii pair<int,int>
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int t=0;
        int n=grid.size();
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        pq.push({grid[0][0],{0,0}}); 
        vis[0][0]=true;
        vector<int> dir={-1,0,1,0,-1};
        while(!pq.empty()){
            int curr=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            t=max(t,curr);
            if(x==n-1 && y==n-1) return t;
            for(int i=0;i<4;i++){
                int newx=x+dir[i];
                int newy=y+dir[i+1];
                if(newx>=0 && newy>=0 && newx<n && newy<n && !vis[newx][newy]){
                    vis[newx][newy]=true;
                    pq.push({grid[newx][newy],{newx,newy}});
                }
            }
        }
        return t;
    }
};

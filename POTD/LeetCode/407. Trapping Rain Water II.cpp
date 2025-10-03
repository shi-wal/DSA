#define pii pair<int,int>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> minheap;
        int vol=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    minheap.push({heightMap[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        vector<int> dir={-1,0,1,0,-1};
        int water=0, minboundary=0;
        while(!minheap.empty()){
            int ht=minheap.top().first;
            int row=minheap.top().second.first;
            int col=minheap.top().second.second;
            minheap.pop();
            minboundary=max(minboundary,ht);
            for(int i=0;i<4;i++){
                int newr=row+dir[i];
                int newc=col+dir[i+1];
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc])        {
                    minheap.push({heightMap[newr][newc],{newr,newc}});
                    vis[newr][newc]=true;
                    if(heightMap[newr][newc]<minboundary){
                        water+=minboundary-heightMap[newr][newc];
                    }
                }
            }
        } 
        return water;
    }
};

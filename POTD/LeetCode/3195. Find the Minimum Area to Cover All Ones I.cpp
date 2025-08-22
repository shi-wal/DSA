class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int minRow=m, maxRow=-1, minCol=n, maxCol=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    minRow=min(minRow,i);
                    minCol=min(minCol,j);
                    maxRow=max(maxRow,i);
                    maxCol=max(maxCol,j);
                }
            }
        }
        return (maxRow-minRow+1)*(maxCol-minCol+1);
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // for(int col=0;col<n/2;col++){
        //     for(int i=0;i<n;i++){
        //         swap(matrix[i][col],matrix[i][n-col-1]);
        //     }
        // }

        // **** or ****

        for(int i=0;i<n;i++) 
            reverse(matrix[i].begin(),matrix[i].end());
    }
};

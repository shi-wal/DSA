class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;
        for(int row=0;row<numRows;row++){
            vector<int> arr;
            for(int j=0;j<=row;j++){
                // First and last values in every row are 1
                if(j==0 || j==row)
                    arr.push_back(1);
                else arr.push_back(mat[row-1][j-1]+mat[row-1][j]);
            }
            mat.push_back(arr);
        }
        return mat;
    }
};

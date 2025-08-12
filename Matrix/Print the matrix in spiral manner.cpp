class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0, bottom=matrix.size()-1;
        int left=0, right=matrix[0].size()-1;
        int d=0;
        vector<int> res;
        while(left<=right && top<=bottom){
            switch(d){
                case 0:
                    for(int i=left;i<=right;i++) res.push_back(matrix[top][i]);
                    top++;
                    break;
                case 1:
                    for(int i=top;i<=bottom;i++) res.push_back(matrix[i][right]);
                    right--;
                    break;
                case 2:
                    for(int i=right;i>=left;i--) res.push_back(matrix[bottom][i]);
                    bottom--;
                    break;
                case 3:
                    for(int i=bottom;i>=top;i--) res.push_back(matrix[i][left]);
                    left++;
                    break;
            }
            if(d==3) d=0;
            else d++;
        }
        return res;
    }
};

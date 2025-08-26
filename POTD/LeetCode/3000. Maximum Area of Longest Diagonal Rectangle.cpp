class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal=0.0;
        int area=0;
        for(vector<int> row:dimensions){
            int len=row[0], wid=row[1];
            double diagonal=sqrt(double(len*len + wid*wid));
            if(diagonal>maxDiagonal || (diagonal==maxDiagonal && len*wid>area)){
                maxDiagonal=diagonal;
                area=len*wid;
            }
        }
        return area;
    }
};

class Solution {
public:
    int totalMoney(int n) {
        int total=0, mon=1,other=2;
        for(int i=1;i<=n;i++){
            if(i%7==1) {
                total+=mon++;
                other=mon;
            }
            else total+=other++;
        }
        return total;
    }
};

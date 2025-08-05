class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(), cnt=0;
        for(int fruit:fruits){
            for(int i=0;i<n;i++){
                if(baskets[i]>=fruit) {
                    baskets[i]=0; cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};

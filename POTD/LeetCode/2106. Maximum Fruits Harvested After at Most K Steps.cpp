class Solution {
    int minSteps(int left, int right, int start){
        return min(abs(start-left)+(right-left), abs(start-right)+(right-left));
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left=0, sum=0, maxFruits=0, n=fruits.size();
        for(int right=0; right<n;right++){
            sum+=fruits[right][1];
            while(left<=right && minSteps(fruits[left][0], fruits[right][0], startPos)>k){
                sum-=fruits[left][1];
                left++;
            }
            maxFruits=max(maxFruits,sum);
        }
        return maxFruits;
    }
};

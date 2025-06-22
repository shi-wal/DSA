//TC:O(N), SC:O(1) (Most optimal solution)

class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int leftmax=0, rightmax=0, total=0;
        while(left<right){ // when left==right, then it stops & this is the max height[i]
            if(height[left]<=height[right]){
                if(leftmax>height[left]){
                    total+= leftmax-height[left];
                }
                else leftmax=height[left];
                left++;
            }

            else{
                if(rightmax>height[right]){
                    total+= rightmax-height[right];
                }
                else rightmax=height[right];
                right--;
            }
        }
        return total;
    }
};

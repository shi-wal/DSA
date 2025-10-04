class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int left=0, right=height.size()-1;
        while(left<right){
            int water=(right-left)*min(height[left],height[right]);
            maxWater=max(maxWater,water);
            height[left]<height[right]?left++:right--;
        }
        return maxWater;
    }
};

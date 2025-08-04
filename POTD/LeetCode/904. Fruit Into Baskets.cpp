class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruit=0;
        int n=fruits.size(), left=0;
        unordered_map<int,int> basket;
        for(int right=0;right<n;right++){
            if(basket.find(fruits[right])==basket.end()){
                while(basket.size()==2){
                    if(--basket[fruits[left]]==0) basket.erase(fruits[left]);
                    left++;
                }
            }
            basket[fruits[right]]++;
            maxFruit=max(maxFruit,right-left+1);
        }
        return maxFruit;
    }
};

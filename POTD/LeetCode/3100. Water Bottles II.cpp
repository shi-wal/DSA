class Solution {
public:
    int maxBottlesDrunk(int full, int numExchange) {
        int drunk=full; //10
        int empty=full; //10
        while(empty>=numExchange){
            empty-=numExchange; //7, 4
            numExchange++; //4, 5
            drunk++; // 11, 12
            empty++; //8, 5
        }
        return drunk;
    }
};

class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size(), seats=0;
        const int mod=1e9+7;
        for(int i=0;i<n;i++) if(corridor[i]=='S') seats++;
        if(seats%2 || seats==0) return 0;
        seats=0;
        int plants=0, i=0;
        long long ans=1;
        while(i<n){
            if(corridor[i]=='S') {
                seats++;
                if(seats==2){
                    plants=0;
                }
                else if(seats==3){
                    ans=(ans*(plants+1))%mod;
                    seats=1;
                }
            }
            else if(seats==2){
                 plants++;
            }
            i++;
        }
        return (int)ans;
    }
};

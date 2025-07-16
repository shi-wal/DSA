class Solution {
  public:
    int countNumbers(int n) {
        int limit=sqrt(n)+1; // taking +1 to avoid risk
        vector<int> checkPrime(limit+1,1), primes;
        for(int i=2;i<=limit;i++){
            if(checkPrime[i]){
                primes.push_back(i);
                for(int j=i*2;j<=limit;j+=i)
                    checkPrime[j]=0; // marking these as non-prime
            }
        }
        int count=0, m=primes.size();
        for(int i=0;i<m;i++){
            if(pow(primes[i],8)<=n) count++;
            for(int j=i+1;j<m;j++)
                if(pow(primes[i],2)*pow(primes[j],2)<=n) count++;
        }
        return count;
    }
};

// not understood

class Solution {
    // Function to compute exponent of prime p in n!
    int countPrimeInFactorial(int n, int p) {
        int count=0;
        while(n>0){
            n/=p;
            count+=n;
        }
        return count;
    }
    
    // Function to compute prime factorization of k
    // Example: If k = 18, then this function returns: {2:1, 3:2} (because 18 = 2 × 3²)
    map<int,int> primeFactors(int k) {
        map<int,int> factors;
        for (int i=2; i*i<=k; ++i) {
            while(k%i==0) {
                factors[i]++;
                k/=i;
            }
        }
        if(k>1) factors[k]++;
        return factors;
    }

  public:
    int maxKPower(int n, int k) {
        map<int,int> kFactors=primeFactors(k);
        int result=INT_MAX;
    
        for(auto it:kFactors) {
            int prime=it.first, exponentInK=it.second;
            int exponentInFact=countPrimeInFactorial(n, prime);
            result=min(result, exponentInFact / exponentInK);
        }
    
        return result;

    }
};

class Solution {
  public:
    int substrCount(string &s, int k) {
        int n=s.length();
        unordered_map<char,int> freq;
        for(int i=0;i<k;i++){
            freq[s[i]]++;  // if (++freq[s[i]] == 1) distinctCount++;
        }
        int cnt=0;
        if(freq.size()==(k-1)) cnt++; // if (distinctCount == k - 1) cnt++;
        for(int i=k;i<n;i++){
            freq[s[i]]++; // if (++freq[s[i]] == 1) distinctCount++;
            if(--freq[s[i-k]]==0)
                freq.erase(s[i-k]); // distinctCount--;
            if(freq.size()==(k-1)) cnt++; // we can maintain a distinctCount variable to avoid hashing overhead, instead of if(freq.size() == k - 1) each time.
        }
        return cnt;
    }
};

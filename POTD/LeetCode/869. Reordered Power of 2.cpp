// Normalize by sorting the digits of each number into a string.
// If two numbers have the same digits, their sorted digit strings will be identical.

class Solution {
    string sortDigits(int x){
        string s=to_string(x);
        sort(s.begin(),s.end());
        return s;
    }
public:
    bool reorderedPowerOf2(int n) {
        string target=sortDigits(n);
        for(int i=0;i<=31;i++)
            if(sortDigits(1<<i)==target) return true;
        return false;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        int n=s.length(), i=0;
        int sign=1;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-') {
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        long long res=0;
        while(i<n && isdigit(s[i])){
            res=10*res + (s[i]-'0');
            if (sign*res <= INT_MIN) {
                return INT_MIN;
            }
            if (sign*res >= INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        return (int)res * sign;
    }
};

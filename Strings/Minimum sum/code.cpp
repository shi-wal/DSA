class Solution {
    //For long input arays we need to add strings as number to avoid int overflow.
    string addStrings(string a, string b) {
        string res="";
        int i=a.size()-1, j=b.size()-1, carry=0;
        while (i>=0 || j>=0 || carry) {
            int sum=carry;
            if (i>=0) sum += a[i--] - '0';
            if (j>=0) sum += b[j--] - '0';
            res+=(sum % 10 + '0');
            carry=sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        string num1="", num2="";
        for(int i=0;i<n;i++){
            if(i%2)
                num1+=arr[i]+'0';
            else
                num2+=arr[i]+'0';
        }
        string res=addStrings(num1,num2);
        int i=0;
        while(i<res.length() && res[i]=='0') i++;
        return res.substr(i);
    }
};

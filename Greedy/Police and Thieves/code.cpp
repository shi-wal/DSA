// Find the maximum number of thieves that can be caught by the police. 
// 1. Each policeman can catch only one thief.
// 2. A policeman cannot catch a thief who is more than k units away from him.
// Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1  Output: 2

// TC:O(N), SC:O(1)
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size(), cnt=0;
        int police=0, thief=0;
        while(police<n && arr[police]!='P') police++;
        while(thief<n && arr[thief]!='T') thief++;
        while(police<n && thief<n){
            if(abs(police-thief)<=k){
                cnt++; police++; thief++;
            }
            else if(thief<police) thief++;
            else if(police<thief) police++;
            while(police<n && arr[police]!='P') police++;
            while(thief<n && arr[thief]!='T') thief++;
        }
        return cnt;
    }
};

/*
Approach:
Maintain 2 variables...miss and repeat. While traversing the array mark the index as negation of that number... so that it is easy to retrive that element if future with abs function.

Eg: arr = [3 3 2] 
i=0:
     arr[arr[0]-1] = arr[3-1] = arr[2] = 2 (Mark this. as -2)
i=1:
     arr[arr[1]-1] = arr[3-1] = arr[2] = 2 (Since this is already negative, dont mark it...and it the repeating character as well, so store it in repeating)
i=2:
     arr[arr[2]-1] = arr[2-1] = arr[1] = 3 (Mark this. as -3)

So, final array becomes:  arr = [3,-3,-2] and repeating = 3

Now, we can see that index 0 is positive only. 
So which ever index is positive in our array, that is our missing character. 
Hence, index 0 is positive...so index+1 = 0+1 = 1 is our missing number.
*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        int repeat=-1, miss=-1;
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0) repeat=abs(arr[i]);
            else arr[abs(arr[i])-1]*=-1;
        } 
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                miss=i+1; break;
            }
        }
        return {repeat,miss};
    }
};

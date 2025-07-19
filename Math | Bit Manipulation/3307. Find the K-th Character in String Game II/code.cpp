// TC: O(log K), SC: O(1)

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int cnt_ops=0;
        long long val=k;
        while(val>1){
            int jumps=ceil(log2(val));
            val-=pow(2,jumps-1);
            cnt_ops+=operations[jumps-1];
        }
        return char('a'+(cnt_ops%26));

        // Brute-force

            // string word="a";
            // int n=operations.size();
            // for(int i=0;i<n;i++){
            //     if(operations[i]==0){
            //         word+=word;
            //     }
            //     else{
            //         int m=word.size();
            //         for(int i=0;i<m;i++){
            //             word+='a'+((word[i]-'a'+1)%26);
            //         }
            //     }
            //     if(word.size()>=k) break;
            // }
            // return word[k-1];
    }
};

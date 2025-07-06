class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int num:arr2)
            freq[num]++;
    }
    
    void add(int index, int val) {
        int old=arr2[index];
        if(--freq[old]==0) freq.erase(old);
        arr2[index]+=val;
        freq[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int num:arr1){
            int req=tot-num;
            if(freq.count(req)) cnt+=freq[req];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

class Solution {
  public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return kthElement(nums2,nums1,k);
        int low=max(0,k-n2); // if k=7 & n2=5, then we must have to pick from nums1. 
        // You cannot take more than n2 from nums2
        int high=min(k,n1); // You cannot take more than n1 from nums1
        int left=k; //how many elemnts should be present in left halve
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1>0) l1=nums1[mid1-1];
            if(mid2>0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1) {
                return max(l1,l2);
                } 
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
};

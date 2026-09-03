class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn=nums1[0];
        bool odd=0;

        for(auto&x:nums1){
            mn=min(mn,x);
            odd|=x&1;

        }
        return(mn & 1)==odd;
    }
};
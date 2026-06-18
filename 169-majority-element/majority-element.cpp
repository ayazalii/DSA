class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;//to map the frequency of an array element
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max=INT_MIN;
        int ans; // majority element
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>max) {
                max=mp[nums[i]];
                ans=nums[i];
            }
        }
       return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> seen;

        for(int i=0;i<nums.size();i++){
            int required=target-nums[i];

            if(seen.count(required)){
                return{seen[required],i};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};
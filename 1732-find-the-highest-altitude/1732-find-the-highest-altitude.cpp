class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxm=0;
        int cur=0;
        for(int i=0;i<gain.size();i++){
            cur+=gain[i];
            maxm=max(maxm,cur);
        }
        return maxm;
    }
};
class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n=a.size();
        for(int i=1;i<n;i++)
        a[i]+=a[i-1];
        int ans=a.back();
        for(int i=n-2;i>0;i--)
        ans=max(ans,a[i]-ans);
        return ans;
    }
};
class Solution {
    vector<vector<int>> dp;
    vector<int> prefix;
    vector<int> a;

    int solve(int l,int r){
        if(l>=r)
        return 0;

        if(dp[l][r]!=-1)
        return dp[l][r];

        int ans=0;

        int leftsum=0;
        int rightsum=prefix[r+1]-prefix[l];

        for(int k=l;k<r;++k){
            leftsum+=a[k];
            rightsum-=a[k];

            if(leftsum<rightsum){
                if(ans>=2*leftsum)
                continue;

                ans=max(ans,leftsum+solve(l,k));
            }
            else if (leftsum>rightsum){
                if(ans>=2*rightsum)
                break;

                ans=max(ans,rightsum+solve(k+1,r));
            }
            else{
                ans=max({
                    ans,

                    leftsum+solve(l,k),
                    rightsum+solve(k+1,r)
                });
            }
        }
        return dp[l][r]=ans;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        a=stoneValue;
        int n=a.size();
        prefix.resize(n+1);
        for(int i=0;i<n;++i)
        prefix[i+1]=prefix[i]+a[i];

        dp.assign(n,vector<int>(n,-1));

        return solve(0,n-1);
    }
};
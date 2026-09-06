class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();

        vector<int> dp(n+1,0);
        int MOD=(int) 1e9 + 7;

        for(int i=1;i<=m;i++){
            int last=1;
            for(int j=1;j<=n;j++){
                int cur=dp[j];
                int take=0,nottake=0;
                if(s[i-1]==t[j-1])
                {
                    take=last;
                }
                nottake=cur;
                dp[j]=(take+nottake)%MOD;
                last=cur;
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 1), down(m, 1);

        // Length 2 initialization
        for (int i = 0; i < m; i++) {
            up[i] = m - 1 - i; // next element greater
            down[i] = i;       // next element smaller
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> nup(m), ndown(m);

            long long pref = 0;
            for (int i = 0; i < m; i++) {
                ndown[i] = pref;
                pref = (pref + up[i]) % MOD;
            }

            long long suff = 0;
            for (int i = m - 1; i >= 0; i--) {
                nup[i] = suff;
                suff = (suff + down[i]) % MOD;
            }

            up = move(nup);
            down = move(ndown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};
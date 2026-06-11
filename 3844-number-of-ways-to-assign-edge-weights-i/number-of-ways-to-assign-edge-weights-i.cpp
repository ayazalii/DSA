class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        queue<int> q;
        vector<bool> vis(n + 1);

        q.push(1);
        vis[1] = true;

        int depth = -1;

        while (!q.empty()) {
            int sz = q.size();
            depth++;

            while (sz--) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return modPow(2, depth - 1);
    }
};
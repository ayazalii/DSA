class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 17;

    vector<vector<int>> up, g;
    vector<int> depth, pw;

    void dfs(int u, int p) {
        up[0][u] = p;

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i))
                u = up[i][u];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][u];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        g.resize(n + 1);
        depth.resize(n + 1);
        up.assign(LOG, vector<int>(n + 1));
        pw.resize(n + 1);

        for (auto& e : edges) {
            int u = e[0], v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0);

        for (int i = 1; i < LOG; i++) {
            for (int j = 1; j <= n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }

        pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = (2LL * pw[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int a = lca(u, v);
            int d = depth[u] + depth[v] - 2 * depth[a];

            ans.push_back(pw[d - 1]);
        }

        return ans;
    }
};
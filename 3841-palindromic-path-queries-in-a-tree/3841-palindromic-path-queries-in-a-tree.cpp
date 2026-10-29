class FenwickTree {
    int n;
    vector<int> bit;

public:
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] ^= delta;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum ^= bit[i];
        }
        return sum;
    }

    void rangeUpdate(int l, int r, int delta) {
        update(l, delta);
        update(r + 1, delta);
    }
};

class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> tin, tout;
    int timer;
    int LOG;

    void dfs(int u, int p, int d) {
        tin[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
        tout[u] = timer;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        LOG++;

        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;

        dfs(0, 0, 0);

        FenwickTree bit(n + 2);

       
        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            bit.rangeUpdate(tin[i], tout[i], mask);
        }

        vector<bool> ans;

        for (const string& qStr : queries) {
            stringstream ss(qStr);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                if (s[u] != c) {
                    int oldMask = 1 << (s[u] - 'a');
                    int newMask = 1 << (c - 'a');
                    int change = oldMask ^ newMask;

                    
                    bit.rangeUpdate(tin[u], tout[u], change);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;

                int lca = getLCA(u, v);

                int maskU = bit.query(tin[u]);
                int maskV = bit.query(tin[v]);
                int maskLCA_Node = 1 << (s[lca] - 'a');

               
                int pathMask = maskU ^ maskV ^ maskLCA_Node;

               
                bool canRearrange = (pathMask == 0) || ((pathMask & (pathMask - 1)) == 0);
                ans.push_back(canRearrange);
            }
        }

        return ans;
    }
};
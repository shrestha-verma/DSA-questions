class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
       
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

       
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

       
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, streak] = pq.top();
            pq.pop();
            if (u == n - 1) {
                return d;
            }
            if (d > dist[u][streak]) {
                continue;
            }

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                int next_streak = (labels[v] == labels[u]) ? (streak + 1) : 1;
                if (next_streak <= k) {
                    if (d + weight < dist[v][next_streak]) {
                        dist[v][next_streak] = d + weight;
                        pq.push({d + weight, v, next_streak});
                    }
                }
            }
        }

        // Destination unreachable
        return -1;
    }
};
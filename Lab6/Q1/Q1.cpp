
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj, int V) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i) {
        for (int it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    if (result.size() != V) {
        cout << "Graph contains a cycle!" << endl;
        return {};
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<vector<int>> adj(n);
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }
    cout << "Topological sorting of the graph: ";
    vector<int> result = topologicalSort(adj, n);

    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}




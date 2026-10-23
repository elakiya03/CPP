#include <iostream>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int v, int parent) {
    visited[v] = true;

    // transverse neighbours
    for (int i : adj[v]) {
        // if neighbour not visited, recurse
        if (!visited[i]) {
            if (dfs(adj, visited, i, v))
                return true;
        }
        // if neighbour visited and not parent, cycle exits
        else if (i != parent)
            return true;
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    // check all components
    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            if (dfs(adj, visited, u, -1))
                return true;
        }
    }
    return false;
}

bool isCycleIterativeDFS(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (visited[i])
            continue;

        stack<pair<int, int>> s;
        s.push({i, -1});

        while (!s.empty()) {
            int curr = s.top().first;
            int parent = s.top().second;

            s.pop();
            if (!visited[curr]) {
                visited[curr] = true;
                for (int neighbour : adj[curr]) {
                    if (!visited[neighbour]) {
                        s.push({neighbour, curr});
                    } else if (neighbour != parent) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool hasCycleIterativeBFS(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (visited[i])
            continue;

        queue<pair<int, int>> q;
        q.push({i, -1});
        visited[i] = true;

        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;

            q.pop();
            for (int neighbour : adj[curr]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push({neighbour, curr});
                } else if (neighbour != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);

    cout << "Has Cycle(Recursive DFS): " << (isCycleIterativeDFS(adj) ? "Yes" : "No") << endl;
    cout << "Has Cycle(Iterative DFS): " << (isCycle(adj) ? "Yes" : "No") << endl;

    cout << "Has Cycle(Iterative BFS): " << (hasCycleIterativeBFS(adj) ? "Yes" : "No") << endl;
}
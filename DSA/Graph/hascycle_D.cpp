#include <iostream>
using namespace std;

// topological sorting - kahn algo
bool hasCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> inDegree(V, 0);
    queue<int> q;

    // count of visited nodes
    int visited = 0;
    // compute indegrees
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }


    // add all vertices with in-degree 0 to queue
    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0)
            q.push(u);
    }

    // topological sort
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return visited != V;
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 5, 0);

    cout << "Has Cycle(BFS - topological sort): " << (hasCycle(adj) ? "Yes" : "No") << endl;
    return 0;
}
#include <iostream>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;
    queue<int> q;

    int src = 0;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

// 1. push source to queue
// 2. mark visited
// 3. if queue is not empty
// 4. pop front and store
// 5. push to vector
// 6. loop through neighbours
// 7. if not visited
// 8. mark visited
// 9. push to queue

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

    cout << "Adjacency List Representation" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " → [ ";
        for (int nb : adj[i]) cout << nb << " ";
        cout << "]\n";
    }

    vector<int> res = bfs(adj);

    cout << "\nBFS" << endl;
    for (int i : res)
        cout << i << " ";
    return 0;
}
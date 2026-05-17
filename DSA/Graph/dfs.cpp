#include <iostream>
using namespace std;

//dfs iterative approach
vector<int> dfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;
    stack<int> s;

    s.push(0);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (visited[curr]) continue;
        visited[curr] = true;
        res.push_back(curr);

        for (int i = adj[curr].size() - 1; i >= 0; i--) {
            int neighbor = adj[curr][i];

            if (!visited[neighbor])
                s.push(neighbor);
        }
    }
    return res;
}

// 1. push source to stack
// 2. while stack not empty,
// 3. pop top 
// 4. if already visited -> ignore,
// 5. else mark visited 
// 6. push it to vector
// 7. loop through neighbuours
// 8. if neighbour is not visited
// 9. push to stack

//"Check visited AFTER removing from stack"

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

    vector<int> res = dfs(adj);

    cout << "\nDFS" << endl;
    for (int i : res)
        cout << i << " ";
    return 0;
}

// dfs - recursive approach

// void dfs(vector<vector<int>>& adj, vector<bool>& visited, int src, vector<int>& res) {
//     visited[src] = true;
//     res.push_back(src);
//     for (int i : adj[src]) {
//         if (visited[i] == false) {
//             dfs(adj, visited, i, res);
//         }
//     }
// }

// vector<int> dfs(vector<vector<int>>& adj) {
//     int V = adj.size();
//     vector<bool> visited(V, false);
//     vector<int> res;
//     dfs(adj, visited, 0, res);
//     return res;
// }
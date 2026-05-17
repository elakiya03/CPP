#include <iostream>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& it : edges) {
        int u = it[0];
        int v = it[1];
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    return adj;
}

vector<vector<int>> createMatrix(int V, vector<vector<int>>& edges) {
    vector<vector<int>> mat(V, vector<int>(V, 0));
    for (auto& it : edges) {
        int u = it[0];
        int v = it[1];
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    return mat;
}

void display(vector<vector<int>> adj) {
}
int main() {
    int v = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

    cout << "Adjacency List Representation" << endl;
    vector<vector<int>> adj = createGraph(v, edges);
    for (int i = 0; i < v; i++) {
        cout << i << " → [ ";
        for (int nb : adj[i]) cout << nb << " ";
        cout << "]\n";
    }

    cout << "\nAdjacency Matrix Representation" << endl;
    vector<vector<int>> mat = createMatrix(v, edges);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
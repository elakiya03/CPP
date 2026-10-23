#include <iostream>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& it : edges) {
        int u = it[0];
        int v = it[1];
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
    }
    return mat;
}

int main() {
    int v = 4;
    vector<vector<int>> edges = {{3, 0}, {1, 2}, {2, 0}};

    cout << "\nAdjacency List Representation" << endl;
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


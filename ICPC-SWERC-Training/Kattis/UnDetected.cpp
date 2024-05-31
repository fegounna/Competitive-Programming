#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    // Constructor to initialize the union-find structure
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // Find the root of the node `u` with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // Path compression
        }
        return parent[u];
    }

    // Union by rank
    void unionS(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};


int main() {
    int N;
    cin >> N;

    vector<vector<int>> sensors(N, vector<int>(3));
    for (int i=0;i<N;i++){
        cin >> sensors[i][0] >>sensors[i][1]  >> sensors[i][2];
    }

    UnionFind uf(N+2);

    int k = 0;
    while (k< N) {
        int x, y, r;
        x = sensors[k][0];
        y = sensors[k][1];
        r = sensors[k][2];

        if (x-r <= 0) {
            uf.unionS(0,k+2);
        }
        if (x+r >= 200) {
            uf.unionS(1, k+2);
        }
        for (int i = 0;i < k;i ++) {
            if (pow(x-sensors[i][0], 2) +pow(y-sensors[i][1], 2) <= pow(r+ sensors[i][2], 2)) {
                uf.unionS( i+2, k+2);
            }
        }

        if (uf.find(0) == uf.find(1)) {
            break;
        }
        k++;
    }

    cout << k << endl;

    return 0;
}

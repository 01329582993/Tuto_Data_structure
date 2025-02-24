#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 100005;

vector<int> parent(MAXN, -1);
vector<pair<int, int>> redundantEdges, newEdges;

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return false;

    if (parent[rootX] > parent[rootY]) swap(rootX, rootY);
    parent[rootX] += parent[rootY];
    parent[rootY] = rootX;
    return true;
}









int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> edges;

    fill(parent.begin(), parent.begin() + n + 1, -1);


    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});

        if (!unite(u, v)) {
            redundantEdges.push_back({u, v});
        }
    }

    vector<int> representatives;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            representatives.push_back(i);
        }
    }

    int changes = representatives.size() - 1;
    cout << changes << endl;

    for (int i = 1; i < representatives.size(); i++) {
        newEdges.push_back({representatives[i - 1], representatives[i]});
    }


    for (int i = 0; i < newEdges.size(); i++) {
        cout << redundantEdges[i].first << " " << redundantEdges[i].second << "   "
             << newEdges[i].first << " " << newEdges[i].second << endl;
    }

    return 0;
}

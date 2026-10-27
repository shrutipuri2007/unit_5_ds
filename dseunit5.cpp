#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int source, destination, cost;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

int findParent(vector<int>& parent, int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] =
           findParent(parent, parent[vertex]);
}

void unionSets(vector<int>& parent,
               vector<int>& rank,
               int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int n, m;

    cout << "Enter number of electrical substations: ";
    cin >> n;

    cout << "Enter number of possible transmission lines: ";
    cin >> m;

    vector<Edge> edges(m);

    cout << "\nEnter source, destination and construction cost:\n";

    for (int i = 0; i < m; i++) {
        cin >> edges[i].source
            >> edges[i].destination
            >> edges[i].cost;
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalCost = 0;
    int selectedEdges = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Transmission Line\tConstruction Cost\n";

    for (int i = 0; i < m; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int cost = edges[i].cost;

        if (findParent(parent, u) !=
            findParent(parent, v)) {

            unionSets(parent, rank, u, v);

            cout << u << " - " << v
                 << "\t\tRs. " << cost << endl;

            totalCost += cost;
            selectedEdges++;

            if (selectedEdges == n - 1)
                break;
        }
    }

    if (selectedEdges != n - 1) {
        cout << "\nNetwork cannot connect all substations.\n";
    } else {
        cout << "\nMinimum Total Construction Cost: Rs. "
             << totalCost << endl;
    }

    return 0;
}

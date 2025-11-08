#include <bits/stdc++.h>
using namespace std;

#define INF 9999

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 8, 5, INF},
        {INF, 0, INF, 2, INF},
        {INF, INF, 0, INF, 7},
        {INF, INF, 1, 0, 4},
        {INF, INF, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}

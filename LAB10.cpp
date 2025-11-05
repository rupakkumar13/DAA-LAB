#include <bits/stdc++.h>
using namespace std;

struct HeapNode {
    int vertex;
    int dist;
};

void build_heap(vector<HeapNode>& heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < heap.size() && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r < heap.size() && heap[r].dist < heap[smallest].dist) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = heap.size() / 2;
        }
    }
}

HeapNode extract_min(vector<HeapNode>& heap) {
    HeapNode root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int i = 0;
    while (true) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < heap.size() && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r < heap.size() && heap[r].dist < heap[smallest].dist) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

void decrease_key(vector<HeapNode>& heap, int vertex, int newDist) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i].vertex == vertex && heap[i].dist > newDist) {
            heap[i].dist = newDist;
            int parent = (i - 1) / 2;
            while (i > 0 && heap[i].dist < heap[parent].dist) {
                swap(heap[i], heap[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }
            break;
        }
    }
}

void dijkstra(int graph[100][100], int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<HeapNode> heap;
    for (int i = 0; i < V; i++) heap.push_back({i, dist[i]});
    build_heap(heap);

    while (!heap.empty()) {
        HeapNode u = extract_min(heap);
        int vertex = u.vertex;
        for (int v = 0; v < V; v++) {
            if (graph[vertex][v] && dist[vertex] != INT_MAX && dist[vertex] + graph[vertex][v] < dist[v]) {
                dist[v] = dist[vertex] + graph[vertex][v];
                decrease_key(heap, v, dist[v]);
            }
        }
    }
    cout<<"Dijkstra Algorithm (using the minheap)"<<endl;
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) cout << i << "\t" << dist[i] << endl;
}

int main() {
    int V = 5;
    int graph[100][100] = {
        {0, 9, 6, 0, 0},
        {9, 0, 11, 5, 0},
        {6, 11, 0, 0, 4},
        {0, 5, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };
    int src = 0;
    dijkstra(graph, V, src);
    return 0;
}

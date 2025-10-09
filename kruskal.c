#include <stdio.h>

#define V 5
#define E 7

typedef struct {
    int u, v, w;
} Edge;

int parent[V];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int x, int y) {
    parent[find(x)] = find(y);
}

void kruskalMST(Edge edges[]) {
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0, i = 0;
    while (count < V - 1) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            printf("%d - %d \t%d\n", u, v, w);
            unionSet(set_u, set_v);
            count++;
        }
        i++;
    }
}

void sortEdges(Edge edges[]) {
    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
}

int main() {
    Edge edges[E] = {
        {0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}
    };

    sortEdges(edges);
    kruskalMST(edges);

    return 0;
}

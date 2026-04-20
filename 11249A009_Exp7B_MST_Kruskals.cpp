#include <stdio.h>
#include <stdlib.h>

int parent[100], rank_[100];

int cmp(const void *a, const void *b) {
    return ((int*)a)[2] - ((int*)b)[2];
}

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

void unite(int u, int v) {
    u = find(u); v = find(v);
    if (rank_[u] < rank_[v]) parent[u] = v;
    else if (rank_[u] > rank_[v]) parent[v] = u;
    else parent[v] = u, rank_[u]++;
}

int kruskal(int n, int e[][3]) {
    for (int i = 0; i < n; i++) parent[i] = i, rank_[i] = 0;
    qsort(e, n, sizeof(e[0]), cmp);
    int cost = 0;
    printf("Edge\tWeight\n");
    for (int i = 0; i < n; i++)
        if (find(e[i][0]) != find(e[i][1])) {
            printf("%d - %d\t%d\n", e[i][0], e[i][1], e[i][2]);
            unite(e[i][0], e[i][1]), cost += e[i][2];
        }
    printf("Min Cost: %d\n", cost);
    return cost;
}

int main() {
    int e[5][3] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    kruskal(5, e);
}

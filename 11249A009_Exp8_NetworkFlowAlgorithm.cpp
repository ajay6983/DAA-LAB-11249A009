#include <stdio.h>
#define N 6
#define INF 1000000000

int cap[N][N], fl[N][N], pred[N], color[N], q[N+2];

int bfs(int s, int t) {
    for (int i = 0; i < N; i++) color[i] = 0;
    int head = 0, tail = 0;
    q[tail++] = s; color[s] = 1; pred[s] = -1;
    while (head != tail) {
        int u = q[head++]; color[u] = 2;
        for (int v = 0; v < N; v++)
            if (!color[v] && cap[u][v] - fl[u][v] > 0)
                { q[tail++] = v; color[v] = 1; pred[v] = u; }
    }
    return color[t] == 2;
}

int fordFulkerson(int s, int t) {
    int maxFlow = 0;
    while (bfs(s, t)) {
        int inc = INF;
        for (int u = t; pred[u] >= 0; u = pred[u])
            inc = inc < cap[pred[u]][u] - fl[pred[u]][u]
                  ? inc : cap[pred[u]][u] - fl[pred[u]][u];
        for (int u = t; pred[u] >= 0; u = pred[u])
            { fl[pred[u]][u] += inc; fl[u][pred[u]] -= inc; }
        maxFlow += inc;
    }
    return maxFlow;
}

int main() {
    cap[0][1]=8; cap[0][4]=3; cap[1][2]=9;
    cap[2][4]=7; cap[2][5]=2; cap[3][5]=5;
    cap[4][2]=7; cap[4][3]=4;
    printf("Max Flow: %d\n", fordFulkerson(0, 5));
}

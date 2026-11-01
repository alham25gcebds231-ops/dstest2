#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* g[20];
int visited[20];
int q[20], f = -1, r = -1;

void addEdge(int u, int v) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->vertex = v;
    ptr->next = g[u];
    g[u] = ptr;
}

void bfs(int start) {
    int i;
    for (i = 0; i < 20; i++) visited[i] = 0;

    f = r = 0;
    q[r] = start;
    visited[start] = 1;

    while (f <= r) {
        int curr = q[f++];
        printf("%d ", curr);

        struct node* temp = g[curr];
        while (temp != NULL) {
            int adj = temp->vertex;
            if (visited[adj] == 0) {
                visited[adj] = 1;
                r++;
                q[r] = adj;
            }
            temp = temp->next;
        }
    }
}

void dfs(int curr) {
    visited[curr] = 1;
    printf("%d ", curr);

    struct node* temp = g[curr];
    while (temp != NULL) {
        int adj = temp->vertex;
        if (visited[adj] == 0) {
            dfs(adj);
        }
        temp = temp->next;
    }
}

int main() {
    int n, e, i, u, v, start;

    for (i = 0; i < 20; i++) g[i] = NULL;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS: ");
    bfs(start);
    printf("\n");

    for (i = 0; i < 20; i++) visited[i] = 0;

    printf("DFS: ");
    dfs(start);
    printf("\n");

    return 0;
}
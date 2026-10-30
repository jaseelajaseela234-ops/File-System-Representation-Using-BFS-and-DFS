
#include <stdio.h>
#include <string.h>

#define MAX 20

int adj[MAX][MAX];
char name[MAX][50];
int n, visited[MAX];

// Breadth First Search
void BFS(int start, char target[]) {
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];

        printf("%s ", name[v]);

        if (strcmp(name[v], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS!");
    else
        printf("\nFile not found using BFS.");
}

// Depth First Search
void DFS(int v, char target[], int *found) {
    visited[v] = 1;

    printf("%s ", name[v]);

    if (strcmp(name[v], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i, target, found);
        }
    }
}

int main() {
    int edges, u, v, start;
    char target[50];
    int found = 0;

    printf("FILE SYSTEM USING BFS AND DFS\n");

    printf("\nEnter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of nodes!");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name of node %d: ", i + 1);
        scanf("%49s", name[i]);
    }

    printf("\nEnter number of connections: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * n) {
        printf("Invalid number of connections!");
        return 1;
    }

    printf("Enter connections (parent child):\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Invalid connection!");
            return 1;
        }

        adj[u - 1][v - 1] = 1;
    }

    printf("\nEnter starting node number: ");
    scanf("%d", &start);

    if (start < 1 || start > n) {
        printf("Invalid starting node!");
        return 1;
    }

    printf("Enter file name to search: ");
    scanf("%49s", target);

    BFS(start - 1, target);

    printf("\n\nDFS Traversal: ");

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(start - 1, target, &found);

    printf("\n");

    if (found)
        printf("File found using DFS!");
    else
        printf("File not found using DFS.");

    printf("\n");

    return 0;
}

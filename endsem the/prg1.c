void dfs(int a[20][20], int n, int source) {
    int visited[10], u, v, i;

    // Initialize visited array to 0
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    int S[20], top = -1;
    S[++top] = source;  // Push the source vertex onto the stack
    visited[source] = 1;  // Mark the source vertex as visited

    while (top >= 0) {
        u = S[top--];  // Pop a vertex from the stack
        for (v = 1; v <= n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;  // Mark the adjacent vertex as visited
                S[++top] = v;  // Push the adjacent vertex onto the stack
            }
        }
        printf(" %d ", u);  // Process the popped vertex (in this case, print it)
    }
}

int main()
{
    int n, a[20][20], i, j, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("The DFS traversal is: ");
    dfs(a, n, source);
    return 0;
}

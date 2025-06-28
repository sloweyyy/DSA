function shortestDistanceAfterQueries(
    n: number,
    queries: number[][],
): number[] {
    const graph = Array.from({ length: n }, () => new Array(n).fill(Infinity));
    for (let i = 0; i < n - 1; i++) {
        graph[i][i + 1] = 1;
    }

    const answer: number[] = [];

    const distances = Array.from({ length: n }, () =>
        new Array(n).fill(Infinity),
    );
    for (let i = 0; i < n; i++) {
        distances[i][i] = 0;
    }
    for (let i = 0; i < n - 1; i++) {
        distances[i][i + 1] = 1;
    }
    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    for (const [u, v] of queries) {
        if (distances[u][v] > 1) {
            distances[u][v] = 1;
            for (let i = 0; i < n; i++) {
                for (let j = 0; j < n; j++) {
                    if (
                        distances[i][u] + distances[u][v] + distances[v][j] <
                        distances[i][j]
                    ) {
                        distances[i][j] =
                            distances[i][u] + distances[u][v] + distances[v][j];
                    }
                }
            }
        }
        answer.push(distances[0][n - 1]);
    }

    return answer;
}

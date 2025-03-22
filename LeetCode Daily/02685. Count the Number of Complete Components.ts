function countCompleteComponents(n: number, edges: number[][]): number {
    const graph = new Map<number, number[]>();
    for (const [u, v] of edges) {
        if (!graph.has(u)) {
            graph.set(u, []);
        }
        if (!graph.has(v)) {
            graph.set(v, []);
        }
        graph.get(u)!.push(v);
        graph.get(v)!.push(u);
    }

    const visited = new Set<number>();
    let completeCount = 0;

    const dfs = (
        node: number,
        component: number[],
        edgeCount: { count: number }
    ) => {
        visited.add(node);
        component.push(node);
        if (graph.has(node)) {
            for (const neighbor of graph.get(node)!) {
                edgeCount.count++;
                if (!visited.has(neighbor)) {
                    dfs(neighbor, component, edgeCount);
                }
            }
        }
    };

    for (let i = 0; i < n; i++) {
        if (!visited.has(i)) {
            const component: number[] = [];
            const edgeCount = { count: 0 };
            dfs(i, component, edgeCount);

            const nodeCount = component.length;
            const expectedEdges = (nodeCount * (nodeCount - 1)) / 2;

            // Each edge is counted twice in the DFS, so divide by 2
            if (edgeCount.count / 2 === expectedEdges) {
                completeCount++;
            }
        }
    }

    return completeCount;
}

var minimumCost = function (n, edges, query) {
    let parent = Array.from({ length: n }, (_, i) => i);
    let minPathCost = Array(n).fill(-1);

    const findRoot = (node) => {
        if (parent[node] !== node) {
            parent[node] = findRoot(parent[node]); // Path compression
        }
        return parent[node];
    };

    for (let [source, target, weight] of edges) {
        let sourceRoot = findRoot(source);
        let targetRoot = findRoot(target);

        minPathCost[targetRoot] &= weight;

        if (sourceRoot !== targetRoot) {
            minPathCost[targetRoot] &= minPathCost[sourceRoot];
            parent[sourceRoot] = targetRoot;
        }
    }

    return query.map(([start, end]) => {
        if (start === end) return 0;
        if (findRoot(start) !== findRoot(end)) return -1;
        return minPathCost[findRoot(start)];
    });
};

public class Solution {
    public class Edge{
        public int id{get;set;}
        public int from{get;set;}
        public int to{get;set;}
        public int cost{get;set;}
    }
    class DSU{
        int[] par, sz;
        public int componentCount;
        public DSU(int n){
            par = new int[n];
            componentCount = n;
            sz = new int[n];
            for(int i = 0; i < n;i++){
                par[i] = i;
                sz[i] = 1;
            }
        }
        public int FindParent(int u){
            if(par[u] == u) return u;
            int p = FindParent(par[u]);
            par[u] = p;
            return p;
        }
        public bool IsSameComponent(int u , int v) => FindParent(u) == FindParent(v);
        public void Join(int u,int v){
            u = FindParent(u);
            v = FindParent(v);
            if(u == v) return;
            if(sz[u] < sz[v]) (u,v) = (v,u);
            par[v] = u;
            sz[u]+=sz[v];
            componentCount--;
        }
    }
    int kruskal(PriorityQueue<Edge,int> edges, int nodes,Edge taken = null){
        int res = 0;
        DSU dsu = new DSU(nodes);
        if(taken != null){
            dsu.Join(taken.from, taken.to);
            res += taken.cost;
        }
        while(dsu.componentCount > 1 && edges.Count > 0){
            var e = edges.Dequeue();
            if(dsu.IsSameComponent(e.from, e.to)) continue;
            dsu.Join(e.from, e.to);
            res += e.cost;
        }
        if(dsu.componentCount > 1) return Int32.MaxValue;
        return res;
    }
    public PriorityQueue<Edge,int> GetEdges(int[][] edges,int skipedIdx = -1){
        PriorityQueue<Edge,int> edgesPq = new(Comparer<int>.Create((a, b) => a.CompareTo(b)));
        for(int i = 0;i < edges.Length;i++){
            if(i == skipedIdx) continue;
            edgesPq.Enqueue(new Edge{id = i,from = edges[i][0], to = edges[i][1],cost = edges[i][2]},edges[i][2]);
        }
        return edgesPq;
    }
    public IList<IList<int>> FindCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        int mstCost =  kruskal(GetEdges(edges),n);
        List<IList<int>> res = new List<IList<int>>(){new List<int>(),new List<int>()};
        for(int i = 0; i < edges.Length;i++){
            int curCost = kruskal(GetEdges(edges,i),n);
            if(curCost > mstCost) res[0].Add(i);
            else{
                Edge taken = new Edge{id = i,from = edges[i][0], to = edges[i][1],cost = edges[i][2]};
                curCost = kruskal(GetEdges(edges),n,taken);
                if(curCost == mstCost)res[1].Add(i);
            } 
        }
        return res;
    }
}
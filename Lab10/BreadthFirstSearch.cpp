#include <cmath> 
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <queue>
#include <algorithm>
#include <list>
#include <climits>
using namespace std;

struct graph {
    std::vector< std::vector<int> > edges;
};

std::function<bool(int, int)> generate_compare_func(std::vector<int> &ref) {
    return [&ref](int i1, int i2) {
        return ref.at(i1 - 1) > ref.at(i2 - 1);
    };
}

// weirdest Dijkstra's implementation I've ever written
std::vector<int> solve(graph& g, int N, int M, int S) {
    std::vector<int> dist(N, 7201);
    dist.at(S - 1) = 0;
    std::set<int> worklist;
    for (int i = 0; i < N; i++) {
        worklist.insert(i + 1);
    }
    std::function<bool(int,int)> ref_func = generate_compare_func(dist);
    while (worklist.size() > 0) {
        std::priority_queue<int, std::vector<int>, decltype(ref_func)> graphPQ(ref_func);
        for (std::set<int>::iterator it = worklist.begin(); it != worklist.end(); ++it) {
            graphPQ.push(*it);
        }
        
        int nextNode = graphPQ.top();
        graphPQ.pop(); //gets the minimum distance from start. 
        // to be honest I could have done this in many other ways other than std::priority_queue 
        // but this looked cool
        worklist.erase(nextNode);
        for (int i = 0; i < N; i++) {
            //cout << "nextNode: " << nextNode << ", i: " << i << " ";;
            if (g.edges[nextNode-1][i]) {
                //cout << "true" << endl;
                int alt = dist.at(nextNode - 1) + 6;
                if (alt < dist.at(i)) {
                    dist.at(i) = alt;
                }
            }
        }
    }
    
    for (std::vector<int>::iterator it = dist.begin(); it != dist.end(); ++it) {
        if (*it == 7201) {
            *it = -1;
        }
    }
    
    dist.erase(dist.begin()+S-1);
    return dist;
}

int main() {
    int T;
    cin >> T;
  
    for (int i = 0; i < T; i++) {
        std::vector< std::vector<int> > currentEdges;
        graph g {
            .edges = currentEdges
        };
        int N;
        int M;
        cin >> N >> M;
        for (int j = 0; j < N; j++) { 
            std::vector<int> edges_from_j(N, 0);
            g.edges.push_back(edges_from_j);
        }
        for (int j = 0; j < M; j++) {
            int v1;
            int v2;
            cin >> v1 >> v2; 
            g.edges[v1-1][v2-1] = 1;
            g.edges[v2-1][v1-1] = 1;
        }
        int S;
        cin >> S;
        vector<int> soln = solve(g, N, M, S);
        for (int j = 0; j < soln.size(); j++) {
            cout << soln.at(j);
            if (j != soln.size() - 1) {
                cout << " ";
            }
        }
        cout << std::endl;
    }
    
    return 0;
}

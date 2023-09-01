#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Edge
{

    int A;
    int B;
    int weight;

    Edge(int a, int b, int w)
    {
        A = a;
        B = b;
        weight = w;
    }

    bool operator<(const Edge &other) const
    {
        return weight > other.weight;
    }
} Edge;

priority_queue<Edge> edges;
vector<int> subTreeIndex;

bool IsNewSubTree(Edge edge)
{
    return subTreeIndex[edge.A] == 0 && subTreeIndex[edge.B] == 0;
}

bool IsSameSubTree(Edge edge)
{
    return subTreeIndex[edge.A] == subTreeIndex[edge.B];
}

bool IsNewNode(Edge edge)
{
    return subTreeIndex[edge.A] == 0 || subTreeIndex[edge.B] == 0;
}

void CreateNewSubTree(Edge edge, int treeIndex)
{
    subTreeIndex[edge.A] = treeIndex;
    subTreeIndex[edge.B] = treeIndex;
}

void AddToSubTree(Edge edge)
{
    if (subTreeIndex[edge.A] == 0)
    {
        subTreeIndex[edge.A] = subTreeIndex[edge.B];
    }
    else
    {
        subTreeIndex[edge.B] = subTreeIndex[edge.A];
    }
}

void MergeSubTrees(Edge edge)
{
    int subTreeIndexToKeep = subTreeIndex[edge.A];
    int subTreeIndexToDiscard = subTreeIndex[edge.B];
    for (int i = 0; i < subTreeIndex.size(); i++)
    {
        if (subTreeIndex[i] == subTreeIndexToDiscard)
        {
            subTreeIndex[i] = subTreeIndexToKeep;
        }
    }
}

int main()
{

    int nNodes, nEdges, nodeA, nodeB, weight, start, c, totalWeight, nodesCount;
    cin >> nNodes >> nEdges;

    subTreeIndex = vector<int>(nNodes, 0);
    edges = priority_queue<Edge>();

    for (int i = 0; i < nEdges; i++)
    {
        cin >> nodeA >> nodeB >> weight;
        nodeA--;
        nodeB--;
        edges.push(Edge(nodeA, nodeB, weight));
    }
    cin >> start;
    c = 1;
    totalWeight = 0;

    while (!edges.empty())
    {
        Edge edge = edges.top();
        if (IsNewSubTree(edge))
        {
            c++;
            CreateNewSubTree(edge, c);
            totalWeight += edge.weight;
        }
        else if (!IsSameSubTree(edge))
        {
            if (IsNewNode(edge))
            {
                AddToSubTree(edge);
            }
            else
            {
                MergeSubTrees(edge);
            }
            totalWeight += edge.weight;
        }
        edges.pop();
    }

    cout << totalWeight << endl;
    return EXIT_SUCCESS;
}

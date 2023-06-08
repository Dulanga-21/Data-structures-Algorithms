#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the MST
vector<pair<pair<int, int>, int>> primMST(const vector<vector<int>>& graph) {
    int numNodes = graph.size();

    vector<int> weights(numNodes, INT_MAX);
    vector<int> parent(numNodes, -1);
    vector<bool> inMST(numNodes, false);

    // Priority queue to store nodes and their keys
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;

    // Start with Node 0
    int startNode = 0;
    priorityQueue.emplace(0, startNode);
    weights[startNode] = 0;

    while (!priorityQueue.empty()) {
        int u = priorityQueue.top().second;
        priorityQueue.pop();
        inMST[u] = true;

        // Iterate through all nodes
        for (int v = 0; v < numNodes; ++v) {
            int weight = graph[u][v];

            // If v is not yet included in MST and weight of (u,v) is smaller than weights[v]
            if (!inMST[v] && weight != 0 && weight < weights[v]) {
                // Update weights value and parent of v
                weights[v] = weight;
                parent[v] = u;
                priorityQueue.emplace(weights[v], v);
            }
        }
    }

    // Create a vector to store MST edges and their weights
    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i = 1; i < numNodes; ++i) {
        int u = parent[i];
        int v = i;
        int weight = weights[i];
        mstEdges.emplace_back(make_pair(u, v), weight);
    }
    return mstEdges;
}

int main() {
    // graph
    vector<vector<int>> graph = {
            {0,3,0,0,0,1},
            {3,0,2,1,10,0},
            {0,2,0,3,0,5},
            {0,1,3,0,5,0},
            {0,10,0,5,0,4},
            {1,0,5,0,4,0}
    };

    // Find the MST
    vector<pair<pair<int, int>, int>> mstEdges = primMST(graph);

    // Display the MST edges and their weights
    cout << "Edge    : Weight" << endl;
    for (const auto &edge: mstEdges) {
        cout << edge.first.first << " - " << edge.first.second << "\t:  " << edge.second << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<vector<int>>& graph, int source){
    int n = graph.size();
    vector<int> times(n, INT_MAX); // Set times as infinity
    times[source] = 0;

    // Create a min-heap priority queue to store vertices and times
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
    priorityQueue.emplace(0, source); // Push source vertex into the priority queue

    while (!priorityQueue.empty()){
        int u = priorityQueue.top().second; // Get the vertex with the minimum weight
        priorityQueue.pop();

        // Visit all neighbors of vertex u
        for (int v = 0; v < n; v++){
            // If there is an edge between u and v
            if (graph[u][v] > 0){
                int weight = graph[u][v]; // Weight of the edge (u, v)

                // If the time to v through u is shorter, update the time
                if (times[u] + weight < times[v]){
                    times[v] = times[u] + weight;
                    priorityQueue.emplace(times[v], v); // Push updated time and vertex into the priority queue
                }
            }
        }
    }
    // Print the shortest times
    for (int i = 0; i < n; i++){
        if (i == source){
            continue;
        }else{
            cout << "Shortest time between City " << source << " and City " << i << " : " << times[i] << endl;
        }
    }
}

int main() {
    // Adjacency matrix for graph
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}};

    int source;
    cout << "Source city : ";
    cin >> source;
    dijkstra(graph, source);

    return 0;
}

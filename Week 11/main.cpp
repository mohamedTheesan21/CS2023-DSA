#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Custom comparator for priority queue
struct EdgeComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void prims(const vector<vector<int>>& graph, int start_node) {
    int num_nodes = graph.size();

    vector<bool> visited(num_nodes, false);  // Keep track of visited nodes
    vector<int> min_weight(num_nodes, INT_MAX);  // Store minimum weight of each node
    vector<int> parent(num_nodes, -1);  // Store the parent of each node in the MST

    priority_queue<pair<int, int>, vector<pair<int, int>>, EdgeComparator> pq;
    pq.push({start_node, 0});
    min_weight[start_node] = 0;

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();

        visited[u] = true;

        // Traverse all neighbors of u
        for (int v = 0; v < num_nodes; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < min_weight[v]) {
                min_weight[v] = graph[u][v];
                parent[v] = u;
                pq.push({v, min_weight[v]});
            }
        }
    }

    // Print the Minimum Spanning Tree
    cout << "Start node: " << start_node << endl;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < num_nodes; i++) {
        if (parent[i] != -1) {
            cout << "Node " << parent[i] << " - Node " << i << ": Weight = " << graph[i][parent[i]] << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = { {0, 3, 0, 0, 0, 1},
                                  {3, 0, 2, 1, 10, 0},
                                  {0, 2, 0, 3, 0, 0},
                                  {0, 1, 3, 0, 5, 0},
                                  {0, 10, 0, 5, 0, 4},
                                  {1, 0, 0, 0, 4, 0}};

    int start_node = 0;
    prims(graph, start_node);

    return 0;
}

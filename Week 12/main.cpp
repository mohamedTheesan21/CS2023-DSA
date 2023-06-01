#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<int>>& graph, int start_node) {
    int n = graph.size();
    vector<int> distance(n, INF);
    vector<int> visited(n, 0);

    distance[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = 1;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v];

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }
    }

    cout << "Shortest Distances from the Source:\n";
    for (int v = 0; v < n; ++v) {
        cout << "City " << start_node << " to City" << v << " : " << distance[v] << endl;
    }
}

int main() {
    vector<vector<int>> graph = { {0, 10, 0, 0, 15, 5},
                                  {10, 0, 10, 30, 0, 0},
                                  {0, 10, 0, 12, 5, 0},
                                  {0, 30, 12, 0, 0, 20},
                                  {15, 0, 5, 0, 0, 0},
                                  {5, 0, 0, 20, 0, 0}};

    int start_node;
    cout << "Enter the start node: ";
    cin >> start_node;

    dijkstra(graph, start_node);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> adj(V);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); 
    }
    vector<int> dist(V, -1); 
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neigh : adj[node]) {
            if (dist[neigh] == -1) { 
                dist[neigh] = dist[node] + 1;
                q.push(neigh);

                if (neigh == end) return dist[neigh]; 
            }
        }
    }
    return -1;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    int start, end;
    cin >> start >> end;
    int result = shortestPath(V, edges, start, end);
    cout << result << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;
vector<int> adj[MAX];
bool visited[MAX];
bool dfs(int node, int parent) {
    visited[node] = true;

    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    cout<<"Enter edges (u v):\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    for(int i = 0; i < V; i++) visited[i] = false;
    bool hasCycle = false;
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }
    if(hasCycle)
        cout<<"Cycle exists in the graph\n";
    else
        cout<<"No cycle in the graph\n";
    return 0;
}

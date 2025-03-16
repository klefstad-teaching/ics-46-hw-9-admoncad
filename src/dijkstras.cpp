#include "dijkstras.h"
#include <queue>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVert = G.size();
    vector<int> distances(numVert, INF);
    vector<bool> visited(numVert, false);
    distances[source] = 0;
    previous.assign(numVert, -1);
    visited.assign(numVert, false);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> minHeap;
    minHeap.push({source, 0});
    while(!minHeap.empty()){
        pair<int,int> current = minHeap.top();
        minHeap.pop();
        int u = current.first;
        if(visited[u]) continue;
        for(Edge edge : G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    if(distances[destination] == INF){
        cout << "No path" << endl;
        return {};
    }
    for(int i = destination; i != -1; i = previous[i]){
        path.push_back(i);
    }

    vector<int> reverse;
    int size = path.size();
    for(int i = size - 1; i >= 0; --i){
        reverse.push_back(path[i]);
    }
    return reverse;
}

void print_path(const vector<int>& v, int total){
    int pathLen = v.size();
    for(int i = 0; i < pathLen; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl << "Total cost is " << total << endl;
}
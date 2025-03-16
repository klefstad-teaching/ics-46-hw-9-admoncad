#include "dijkstras.h"
using namespace std;

int main(){
    Graph G;
    file_to_graph("largest.txt", G);

    vector<int> previous;
    int source = 1;
    vector<int> distances = dijkstra_shortest_path(G, source, previous); 

    int destination = 4;
    vector<int> path = extract_shortest_path(distances, previous, destination);

    print_path(path, 5);
}
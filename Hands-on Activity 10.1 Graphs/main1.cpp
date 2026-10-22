#include <iostream>
#include"new.h"



// graph implementation
int main(){
    // graph edges array
    graphEdge edges[] = {
        // (x, y, W)->edge from x to y with weight w
        {0, 1, 2}, {0, 2, 4}, {1, 4, 3}, {2, 3, 2}, {3, 1, 4}, {4, 3, 3}
    };
    int N = 6; //Number of vertices in the graph
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    // construct graph
    DiaGraph diagraph(edges, n, N);
    // print adjacency list represenatation of the graph
    std::cout << "Graph adjacency list " << std::endl << "(start_vertex, end_vertex, weight): " << std::endl;

    for(int i = 0; i < N; i++){
        // display adjacentvertices of vertex i
        display_AdjList(diagraph.head[i], i);
    };
    return 0;
}
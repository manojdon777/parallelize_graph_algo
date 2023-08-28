#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generategraph.h"

// typedef struct {
//     int x;
//     int y;
// } Edge;

void generateGraph(int **graph, int vertices, int edges) {

    int tot_edges = (vertices * (vertices - 1)) / 2;
    Edge* all_possible_edges = (Edge *)malloc(tot_edges * sizeof(Edge));
    int edgeIndex = 0;
    srand(time(NULL));
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j <= i; j++) {
            if (i != j) {
                all_possible_edges[edgeIndex].x = i;
                all_possible_edges[edgeIndex].y = j;
                edgeIndex++;
            }
        }
    }

    // for (int i = 0; i < edges; i++) {
    int i = 0;
    while(i<edges){
        int index = rand() % edgeIndex;
        int x = all_possible_edges[index].x;
        int y = all_possible_edges[index].y;
        if(x != y){
            graph[x][y] = 1;
            graph[y][x] = 1;
            i++;
        }
    }

}
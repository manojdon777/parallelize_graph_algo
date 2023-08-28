#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generategraph.h"

// typedef struct {
//     int x;
//     int y;
// } Edge;

void generateGraph(int **graph, int vertices, int edges) {
    Edge all_possible_edges[(vertices * (vertices - 1)) / 2];
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
        // graph[i] = all_possible_edges[index];
        // for (int j = index; j < edgeIndex - 1; j++) {
        //     all_possible_edges[j] = all_possible_edges[j + 1];
        // }
        // edgeIndex--;
        int x = all_possible_edges[index].x;
        int y = all_possible_edges[index].y;
        if(x != y){
            graph[x][y] = 1;
            graph[y][x] = 1;
            i++;
        }


    }

}
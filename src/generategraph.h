#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

typedef struct {
    int x;
    int y;
} Edge;

void generateGraph(int **graph, int vertices, int edges);

#endif

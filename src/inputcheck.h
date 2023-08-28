#ifndef INPUT_CHECK_H
#define INPUT_CHECK_H
#include <stdbool.h>

void dfs(int vertex, int vertices);

int countComponents(int ** graph, int vertices);

bool ifUndirected(int **graph, int vertices);

#endif
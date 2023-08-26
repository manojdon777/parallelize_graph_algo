#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define vertices 10
#define edges 20

typedef struct {
    int x;
    int y;
} Edge;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    Edge graph[edges];
    Edge all_possible_edges[(vertices * (vertices - 1)) / 2];
    // int
    int edgeIndex = 0;
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j < i; j++) {
            if (i != j) {
                all_possible_edges[edgeIndex].x = i;
                all_possible_edges[edgeIndex].y = j;
                edgeIndex++;
            }
        }
    }

    for (int i = 0; i < edges; i++) {
        int index = rand() % (edgeIndex);
        graph[i] = all_possible_edges[index];
        for (int j = index; j < edgeIndex - 1; j++) {
            all_possible_edges[j] = all_possible_edges[j + 1];
        }
        edgeIndex--;
    }

    // Print the generated edges
    for (int i = 0; i < edges; i++) {
        printf("(%d, %d)\n", graph[i].x, graph[i].y);
    }

    return 0;
}

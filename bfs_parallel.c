#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10

int queue[N];
int visited[N];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == N - 1)
        printf("Queue is full.\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        vertex = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return vertex;
    }
    return -1;
}

void parallel_bfs(int rank, int size, int graph[N][N]) {
    // Calculate work distribution for each process
    int chunk_size = N / size;
    int start = rank * chunk_size;
    int end = (rank == size - 1) ? N : start + chunk_size;
    
    // Local arrays for visited and queue
    int local_visited[chunk_size];
    int local_queue[chunk_size];
    int local_front = -1, local_rear = -1;
    
    for (int i = 0; i < chunk_size; i++)
        local_visited[i] = 0;

    local_front = local_rear = -1;

    // Master process initializes BFS
    if (rank == 0) {
        enqueue(0);
        visited[0] = 1;
    }

    // Broadcast visited array from master to all processes
    MPI_Bcast(visited, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Main parallel BFS loop
    while (1) {
        MPI_Bcast(&front, 1, MPI_INT, 0, MPI_COMM_WORLD);
        
        if (front == -1)
            break;
        
        int current = dequeue();
        // printf("process = %d  node = %d\n", rank, current + 1);
        printf("%d ", current + 1);
        
        // Process its own portion of the graph
        for (int i = start; i < end; i++) {
            if (graph[current][i] == 1 && !local_visited[i - start]) {
                enqueue(i);
                local_visited[i - start] = 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    int graph[N][N] = {0};
    int i, j;
    FILE *file;
    int source, destination;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (file = fopen("input_file.txt", "r")) {
        while (fscanf(file, "%d %d", &source, &destination) == 2)
            graph[source - 1][destination - 1] = 1;

        parallel_bfs(rank, size, graph);
    }
    else {
        printf("Error in reading file\n");
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}

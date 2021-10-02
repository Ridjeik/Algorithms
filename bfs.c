#include <stdio.h>
#include <stdlib.h>

void bfs(int size, int start, char *edges, int *distance, int *parent);

int main()
{
    int vertices;
    printf("Vertices: ");
    scanf("%i", &vertices);

    char *edges = calloc(vertices*vertices, sizeof(char));
    int val = 0;
    for(int i = 0; i < vertices; i++){
        for(int j = i; j < vertices; j++){
            if(i==j){
                *(edges + i*vertices + j) = 0;
                continue;
            }
            
            printf("From %d to %d (1|0): ", i, j);
            scanf("%d", &val);
            if(val != 0){
                *(edges + i*vertices + j) = *(edges + j * vertices + i) = 1;
            }
            else{
                *(edges + i*vertices + j) = *(edges + j * vertices + i) = 0;
            }
        }
    }

    int *distance = calloc(vertices, sizeof(int));
    for(int i = 0; i < vertices; i++){
        distance[i] = -1;
    }
    
    int *parent = calloc(vertices, sizeof(int));
    for(int i = 0; i < vertices; i++){
        parent[i] = -1;
    }
    int components = 0;
    for(int i = 0; i < vertices; i++){
        if(parent[i] == -1){
            components++;
            bfs(vertices, i, edges, distance, parent);
        }
        printf("%i: ", i);
        if(parent[i] == -1) printf("starting point");
        else{
            printf("%i", i);
            int vertix = i;
            while(parent[vertix] != -1){
                printf("-%i", parent[vertix]);
                vertix = parent[vertix];
            }
            printf("; D=%i",distance[i]);
        }
        printf("\n");
        
    }
    printf("\nComponents: %i\n", components);
    return 0;
}

void bfs(int size, int start, char *edges, int *distance, int *parent)
{
    char *used = calloc(size, sizeof(char));
    for(int i = 0; i < size; i++){
        used[i] = 0;
    }
    int *queue = calloc(size, sizeof(char));
    int queue_end = 0, queue_head = 0;
    
    used[start] = 1;
    parent[start] = -1;
    distance[start] = 0;

    queue[queue_end] = start;
    queue_end++;

    while(queue_head != queue_end){
        int vertix = queue[queue_head];
        queue_head++;
        for(int i = 0; i < size; i++){
            if(*(edges + vertix*size + i)){
                if(!used[i]){
                    used[i] = 1;
                    queue[queue_end] = i;
                    queue_end++;
                    parent[i] = vertix;
                    distance[i] = distance[vertix] + 1;
                }
            }
        }
    }
}
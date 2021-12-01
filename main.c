
#include"cgraph/cgraph.h"
#include<stdio.h>
#include<stdlib.h>

int num_vertices, num_edges;

int readFile(int **edges, int **weight){
    int i;
    FILE *f;

    f = fopen("../input1.txt", "r");
    if (f == NULL){
        printf("ERROR OPEN FILE");
        return 0;
    }
    fscanf(f, "%d %d\n", &num_vertices, &num_edges);

    *edges = (int*)malloc(num_edges * 2 * sizeof(int));    
    *weight = (int*)malloc(num_edges * sizeof(int));
    for (i = 0; i < num_edges * 2; i = i+2){
        fscanf(f, "%d %d", *edges + i, *edges + i + 1);
        fscanf(f, "%d\n", *weight + i/2);
    }
    fclose(f);
    return 1;
}
int main()
{
    int *edges, *father, *dist, *weight, *prufer, *res_prufer, *color, *pre, *post;
    int min_weight;
    readFile(&edges, &weight);
    cgraph_t g = cgraph_create(edges,num_edges, CGRAPH_UNDIRECTED);
    
    //cgraph_shortest_path_dijkstra(g, 0, weight, CGRAPH_OUT, &father, &dist);
    //cgraph_bfs(g, 0, CGRAPH_ALL, &father, &dist);
    min_weight = cgraph_MST(g, weight, &father, &dist);
    
    for (int i = 0; i < g->v_num;i++){
        printf("father[%d] = %d, ", i, father[i]);
    }
    printf("\n");
    for (int i = 0; i < g->v_num;i++){
        printf("dist[%d] = %d, ", i, dist[i]);
    }
    printf("\nmin_weight = %d\n", min_weight);
    //free(res_prufer);
    //free(color);
    //free(prufer);
    free(edges);
    free(father);
    free(dist);
    //free(pre);
    //free(post);
    //free(weight);
    cgraph_free(&g);
    return 0;
}

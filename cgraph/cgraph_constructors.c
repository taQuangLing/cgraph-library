#include"cgraph_constructors.h"
#include"libfdr/dllist.h"
#include<stdlib.h>


cgraph_t cgraph_create(int *edges, int num_edges, cgraph_directed directed)
{
    int i, max = -1;
    cgraph_t g;
    g = (cgraph_t)malloc(sizeof(struct cgraph));
    g->from = (int*)malloc(num_edges*sizeof(int));
    g->to = (int*)malloc(num_edges*sizeof(int));
    for (i = 0; i < num_edges*2; i++){
        if (max < edges[i])max = edges[i];
        if (i % 2 == 0)g->from[i/2] = edges[i];
        else 
        g->to[(i-1)/2] = edges[i];
    }
    g->e_num = num_edges;
    g->v_num = max+1;
    g->directed = directed;
    return g;
}

void cgraph_free(cgraph_t *g){
    free((*g)->from);
    free((*g)->to);
    free(*g);
}


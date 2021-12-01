#include"cgraph.h"
#include"cgraph_dfs.h"
#include<stdlib.h>

int num_edges, num_vertices;

void previsit(int *pre,int i, int *clock)
{   
    pre[i] = *clock;
    (*clock)++;
}
void postvisit(int *post, int i, int *clock){
    post[i] = *clock;
    (*clock)++;
}
void explore(   cgraph_t g, 
                int *visited,
                int u,
                cgraph_mode mode,
                int *clock,
                int *pre,
                int *post,
                int *father,
                int *dist)
{
    int i, v;
    i = 0;
    previsit(pre, u, clock);
    visited[u] = 1;
    while (1){
        v = cgraph_neighbor(g, u, &i, mode);
        if (v == -1)break;
        if (visited[v] == 0){
            father[v] = u;
            dist[v] = dist[u]+1;
            explore(g, visited, v, mode, clock, pre, post, father, dist);
        }
        i++;
    }
    postvisit(post, u, clock);
}
void cgraph_dfs(cgraph_t g,
                int root,
                cgraph_mode mode,
                int **pre,
                int **post,
                int **father,
                int **dist)
{
    int i, clock = 1;

    (*pre) = (int*)calloc(g->v_num , sizeof(int));  //Giá trị pre của đỉnh 
    (*post) = (int*)calloc(g->v_num , sizeof(int)); // Giá trị post của đỉnh 
    (*father) = (int*)malloc(g->v_num * sizeof(int));   //Lưu cha của đỉnh có chỉ số i 
    (*dist) = (int*)malloc(g->v_num * sizeof(int));     // Lưu khoảng cách từ đỉnh bắt đầu đến đỉnh có chỉ số i
    int *visited = (int*)calloc(g->v_num , sizeof(int));

    for (i = 0; i < g->v_num; i++){
        (*father)[i] = -1;
        (*dist)[i] = -1;
    }
    (*dist)[root] = 0;
    (*father)[root] = 0;
    explore(g, visited, root, mode, &clock, *pre, *post, *father, *dist);
    for (i = 0; i < g->v_num; i++){
        if (visited[i] == 0){
            explore(g, visited, i, mode, &clock, *pre, *post, *father, *dist);
        }
    }
    free(visited);
}

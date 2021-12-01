
#include"cgraph_paths.h"
#include"cgraph_constructors.h"
#include"cgraph_queue.h"
#include"libfdr/dllist.h"
#include<stdlib.h>
#define EX_POST 999999999

int cgraph_neighbor(cgraph_t g,
                    int u, 
                    int *i, 
                    cgraph_mode mode) // tìm hàng xóm của 'u' 
{
    int j = *i;
    for (*i = j; *i < g->e_num; (*i)++){
        if (g->from[*i] == u){
            if (mode == CGRAPH_ALL || mode == CGRAPH_OUT)return g->to[*i];
        }
        if (g->to[*i] == u){
            if (mode == CGRAPH_ALL || mode == CGRAPH_IN)return g->from[*i];
        }
    }
    return -1;
}


void cgraph_bfs(cgraph_t g,  
                int root, 
                cgraph_mode mode, 
                int **father, // lưu node cha của 'i'
                int **dist)    // lưu khoảng cách từ root đến 'i'
{   
    *father = (int*)malloc(sizeof(int) * g->v_num);
    *dist = (int*)malloc(sizeof(int) * g->v_num);
    int i, u, v;

    Dllist q = make_queue();

    for(i = 1; i < g->v_num; i++)
        *(*dist + i) = g->e_num + EX_POST; // khoi tao gia tri cua dist bang duong vo cung

    (*dist)[root] = 0;
    (*father)[root] = 0;

    en_queue(q, root);
    while(!empty_queue(q)){
        i = 0;
        de_queue(q, &u);
        while(1){
            v = cgraph_neighbor(g, u, &i,mode);

            if (v == -1)break;
            if ((*dist)[v] > g->e_num){
                en_queue(q, v);

                (*dist)[v] = (*dist)[u] + 1;
                (*father)[v] = u;
            }
            i++;
        }
    }
}
int deletemin(Dllist q, int *dist)
{
    Dllist ptr = q, p;
    int v, min = EX_POST;
    dll_traverse(ptr, q){
        if (min > dist[jval_i(ptr->val)]){
            min = dist[jval_i(ptr->val)];
            p = ptr;
        }
    }
    min = jval_i(p->val);
    dll_delete_node(p);
    return min;
}

void decreasekey(Dllist q, int v){    
    Jval val = new_jval_i(v);
    dll_append(q, val);
}
void cgraph_shortest_path_dijkstra(cgraph_t g, 
                                   int root, 
                                   int *weight, 
                                   cgraph_mode mode, 
                                   int **father, 
                                   int **dist)
{
    int i, u, v;
    *father = (int*)malloc(sizeof(int) * g->v_num);
    *dist = (int*)malloc(sizeof(int) * g->v_num);
    int * visited = (int*)calloc(g->v_num, sizeof(int));
    Dllist q = make_queue();
    for (i = 0; i < g->v_num; i++){
        (*dist)[i] = EX_POST;
        (*father)[i] = -1;
    }
    (*dist)[root] = 0;
    en_queue(q, root);
    while(!empty_queue(q)){
        u = deletemin(q, *dist);
        visited[u] = 1;
        i = 0;
        while(1){
            v = cgraph_neighbor(g, u, &i, mode);
            if (v == -1)break;
            if ((*dist)[v] > (*dist)[u] + weight[i] && visited[v] == 0){
                if ((*father)[v] == -1)decreasekey(q, v);
                (*dist)[v] = (*dist)[u] + weight[i];
                (*father)[v] = u;
            }
            i++;
        }
    }
    free(visited);
}



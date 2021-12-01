#include"cgraph.h"
#include"libfdr/dllist.h"
#include<stdlib.h>



int cgraph_MST(cgraph_t g, int *weight, int **father, int **dist){
    int i, v, u, min_weight = 0;
    int *visited;
    Dllist q = make_queue();

    (*father) = (int*)malloc(g->v_num * sizeof(int));
    (*dist) = (int*)malloc(g->v_num * sizeof(int));
    visited = (int*)calloc(g->v_num, sizeof(int)); //Đánh dấu những đỉnh thuộc S 

    for ( i = 0; i < g->v_num; i++){
        (*father)[i] = -1;
        (*dist)[i] = EX_POST;
    }
    (*father)[0] = 0;
    (*dist)[0] = 0;
    en_queue(q, 0);
    while(!empty_queue(q)){
        i = 0;
        u = deletemin(q, *dist); // Trả về đỉnh có dist nhỏ nhât và xóa khỏi hàng đợi
        visited[u] = 1;
        while(1){
            v = cgraph_neighbor(g, u, &i, CGRAPH_ALL);
            if (v == -1)break;
            if ((*dist)[v] > weight[i] && visited[v] != 1){
                if ((*father)[v] == -1)
                    decreasekey(q, v);  //Thêm đỉnh v vào hàng đợi
                (*father)[v] = u;
                (*dist)[v] = weight[i];
            }
            i++;
        }
    }
    for (i = 1; i < g->v_num;i++)min_weight += (*dist)[i];
    free(visited);
    return min_weight;
}
#include"cgraph.h"
#include"cgraph_pruferCode.h"
#include<stdlib.h>

int rank_1(int *rank, int n){
    int min = EX_POST, min_i = 1;
    while(rank[min_i] != 1 && min_i < n)min_i++;
    return min_i;
}
int rank_min(int *dem, int n){
    int i = 1;
    while(dem[i] != 0)i++;
    return i;
}
void cgraph_pruferCode(cgraph_t g, int **prufer)
{
    int min_i, i, v, n = 0;
    (*prufer) = (int*)malloc((g->v_num-1) * sizeof(int));
    int *rank = (int*)calloc(g->v_num, sizeof(int));
    dem_rank(g, rank);
    while(n < g->v_num-1){
        i = 0;
        min_i = rank_1(rank, g->v_num);
        while(1){
            v = cgraph_neighbor(g, min_i, &i, CGRAPH_ALL);
            if (rank[v] == 0)i++;
            else
            break;
        }
        (*prufer)[n++] = v;
        rank[min_i]--;rank[v]--;
    }
}

void cgraph_restore_pruferCode(cgraph_t g, int *prufer, int **res_prufer)
{
    int i, min;
    (*res_prufer) = (int*)malloc((g->v_num-1) * sizeof(int));
    int *dem = (int*)calloc(g->v_num, sizeof(int));
    for (i = 0; i < g->v_num-2; i++)dem[prufer[i]]++;
    for (i = 0; i < g->v_num-1; i++){
        min = rank_min(dem, g->v_num);
        (*res_prufer)[i] = min;
        dem[min] = 1;
        dem[prufer[i]]--;
    }
}
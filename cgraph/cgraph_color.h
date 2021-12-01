#ifndef _CGRAPH_COLOR_
#define _CGRAPH_COLOR_
 

#include"cgraph.h"


void refresh(int *arr, int n);

int check_chinh_quy(cgraph_t g, int *rank, int rank_max);

void add_sorting(int *sort, int top, int *v);

void sorting_t(cgraph_t g, int *sort, int *rank, int top);

int check_neighbor(cgraph_t g, int u, int v);

int dem_rank(cgraph_t g, int *rank);

void cgraph_color(cgraph_t g, int **color);


#endif
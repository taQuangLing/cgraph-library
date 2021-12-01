#ifndef _CGRAPH_DFS_
#define _CGRAPH_DFS_

#include"cgraph.h"



void previsit(int *pre,int i, int *clock);

void postvisit(int *post, int i, int *clock);

void explore(   cgraph_t g, 
                int *visited,
                int u,
                cgraph_mode mode,
                int *clock,
                int *pre,
                int *post,
                int *father,
                int *dist);

void cgraph_dfs(cgraph_t g,
                int root,
                cgraph_mode mode,
                int **pre,
                int **post,
                int **father,
                int **dist);


#endif
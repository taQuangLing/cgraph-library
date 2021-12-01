#ifndef _CGRAPH_PATHS_
#define _CGRAPH_PATHS_

#include"cgraph_constructors.h"
#include"cgraph_queue.h"
#include"libfdr/dllist.h"

 
int cgraph_neighbor(cgraph_t g,
                    int u, 
                    int *i, 
                    cgraph_mode mode); // tìm hàng xóm của 'u' 

void cgraph_bfs(cgraph_t g,  
                int root, 
                cgraph_mode mode, 
                int **father, // lưu node cha của 'i'
                int **dist);    // lưu khoảng cách từ root đến 'i'

void decreasekey(Dllist q, int v);

int deletemin(Dllist q, int *dist);

void cgraph_shortest_path_dijkstra(cgraph_t g, 
                                   int root, 
                                   int *weight, 
                                   cgraph_mode mode, 
                                   int **father, 
                                   int **dist);








#endif
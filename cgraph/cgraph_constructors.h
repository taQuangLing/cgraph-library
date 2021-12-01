#ifndef _CONSTRUCTORS_
#define _CONSTRUCTORS_

#include"libfdr/dllist.h"
#define EX_POST 999999999
typedef enum{
    CGRAPH_ALL = 3, // đồ thị vô hướng
    CGRAPH_IN = 2, // đồ thị có hướng nhưng cạnh có chiều ngược lại "<--"
    CGRAPH_OUT = 1  // đồ thị có hướng, cạnh có chiều đi ra "-->"
}cgraph_mode; 

typedef enum{
    CGRAPH_DIRECTED = 1, // đồ thị có hướng
    CGRAPH_UNDIRECTED = 0 // đồ thị vô hướng 
}cgraph_directed;

typedef struct cgraph
{
    int *from; // cột thứ nhất 
    int *to;    // cột thứ hai 
    int e_num; // số cạnh 
    int v_num; // số đỉnh 
    int directed; // style edges // cgraph_directed 
}*cgraph_t;

cgraph_t cgraph_create( int *edges,         // Danh sách cạnh 
                        int num_edges,      // Số cạnh 
                        cgraph_directed directed);  //Trạng thái cạnh 

void cgraph_free(cgraph_t *g);


#endif
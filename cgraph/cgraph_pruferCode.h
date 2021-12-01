#ifndef _CGRAPH_PRUFER_
#define _CGRAPH_PRUFER_

#include"cgraph.h"


int rank_1(int *rank, int n); //Trả về đỉnh có rank = 1

int rank_min(int *dem, int n); // Trả về đỉnh có rank nhỏ nhất 

void cgraph_pruferCode(cgraph_t g, int **prufer); //Chuyển sang mã prufer 

void cgraph_restore_pruferCode(cgraph_t g, int *prufer, int **res_prufer); // Khôi phục mã prufer 

#endif
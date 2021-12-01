#include"cgraph.h"
#include"cgraph_color.h"
#include<stdlib.h>



void refresh(int *arr, int n){  // Làm mới mảng, = memset
    for (int i = 0; i < n; i++)arr[i] = 0;
}
int check_chinh_quy(cgraph_t g, int *rank, int rank_max){   // Kiểm tra nếu là đồ thị chính quy 
    int i;                                                  //  trả về rank bất kì
    for (i = 0; i < g->v_num; i++){                         //  không chính quy trả về rank < rank_max 
        if (rank[i] < rank_max){
            return i;
        }
    }
    return 0;
}

void add_sorting(int *sort, int top, int *v) // Thêm vào mảng sorting
{
    sort[(*v)++] = top;                      
}

void sorting_t(cgraph_t g, int *sort, int *rank, int top){// 
    int i, j,  neibor, v = 0;
    int *dist = (int*)malloc(g->v_num * sizeof(int));

    refresh(dist, g->v_num);

    add_sorting(sort, top, &v);     // Gán cho đỉnh "top" có giá trị v = 0

    dist[top] = 1;  
    for (i = 0; i < g->v_num-1; i++){                
        j = 0;
        while(1){
            neibor = cgraph_neighbor(g, sort[i], &j, CGRAPH_ALL); // Tìm hàng xóm và gán giá trị tăng dần của v 
            if (neibor == -1)break;
            if (dist[neibor] == 0){
                add_sorting(sort, neibor, &v); 
                dist[neibor] = 1;
            }
            j++;
        }
        if (sort[g->v_num-1] != 0)break;
    }
    free(dist);
}
int check_neighbor(cgraph_t g, int u, int v){  // kiểm tra tồn tại cạnh u-v
    int i;
    for (i = 0; i < g->e_num; i++){
        if (g->from[i] == u && g->to[i] == v)return 1;
        if (g->from[i] == v && g->to[i] == u)return 1;
    }
    return 0;
}
int dem_rank(cgraph_t g, int *rank){ // Đếm bậc của đỉnh và cho vào mảng rank 
    int i, rank_max = -1, rk;
    for (i = 0; i < g->e_num; i++){
        rk = ++rank[g->from[i]];
        if (rk > rank_max)rank_max = rk;
        rk = ++rank[g->to[i]];
        if (rk > rank_max)rank_max = rk;
    }
    return rank_max;
}

void cgraph_color(cgraph_t g, int **color){
    int i, j, col, v_max, rank_max, k;
    int *dem;

    int *sorting = (int*)malloc(g->v_num *sizeof(int));
    int *rank = (int*)malloc(g->v_num * sizeof(int));
    *color = (int*)malloc(g->v_num*sizeof(int));

    refresh(sorting, g->v_num);
    refresh(rank, g->v_num);
    refresh((*color), g->v_num);
    
	// Khởi tạo 
    rank_max = dem_rank(g, rank);// Đếm rank 

    dem = (int*)malloc(rank_max * sizeof(int));
    refresh(dem, rank_max);

    v_max = check_chinh_quy(g, rank, rank_max); // Kiểm tra đồ thị chính quy và trả về đỉnh có bậc < bậc lớn nhất 

	sorting_t(g, sorting, rank, v_max);    // Các đỉnh được đưa vào mảng sorting theo thứ tự v0->vn 

	(*color)[sorting[0]] = 1;              // bắt đầu tô màu 
	for(i = 1;i < g->v_num; i++){
		k = 0;
        for (j = 0; j < i; j++){
            if (check_neighbor(g, sorting[i], sorting[j]))dem[(*color)[sorting[j]] - 1] = 1;
        }
        while(dem[k] > 0)k++;
        (*color)[sorting[i]] = k+1;     // mảng dem dùng để đếm những màu mà hàng xóm của sorting[i] đã dùng 
        refresh(dem, rank_max);
	}
    free(sorting);
    free(rank);
    free(dem);
}

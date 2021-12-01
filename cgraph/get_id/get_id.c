
#include"../cgen/s2i.h"
#include"../cgen/svector.h"
#include"get_id.h"



static int get_save_id(bn_tree_t *t, vector_t *v, char str, int *id_max)
{
    int res = s2i_value(*t, str);
    if (res != k_s2i_invalid)return res;
    s2i_insert(*t, str, *id_max);
    svec_push_back(v, str); 
    res = *id_max;
    ++(*id_max);
    return res;
}

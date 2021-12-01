#include"cgraph_queue.h"
#include"libfdr/dllist.h"


Dllist make_queue()
{
    Dllist queue;
    queue = new_dllist();
    return queue;
}
 void free_queue(Dllist queue){
    free_dllist(queue);
}
void en_queue(Dllist q, int val){
    Jval jval = new_jval_i(val);
    dll_append(q, jval);
}
 int de_queue(Dllist q, int *out){
    if (dll_empty(q))return -1;
    *out = jval_i(dll_first(q)->val);
    dll_delete_node(dll_first(q));
    return 1;
}
 int val_queue(Dllist q){
    return jval_i(dll_val(q));
}
 int empty_queue(Dllist q)
{
    return dll_empty(q);
}
 void insert_before(Dllist q, int val){
    Jval v_i = new_jval_i(val);
    dll_insert_b(q, v_i);
}
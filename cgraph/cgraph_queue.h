#ifndef _QUEUE_
#define _QUEUE_

#include"libfdr/dllist.h"


Dllist make_queue();

void free_queue(Dllist q);

void en_queue(Dllist q, int val);

int de_queue(Dllist q, int *out);

int val_queue(Dllist q);

void insert_before(Dllist q, int val);

int empty_queue(Dllist q);
#define dll_rtraverse(ptr, list) \
  for (ptr = list->flink; ptr != list; ptr = ptr->flink)




#endif

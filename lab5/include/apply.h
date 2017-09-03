#ifndef _APPLY_H_
#define _APPLY_H_
#include "position.h"
#include "clist.h"
void count(intrusive_node* node, void *cnt);
void print(intrusive_node *node, void *format);
void loadtxt(intrusive_list *list, char *finname);
void loadbin(intrusive_list *list, char *finname);
void savebin(intrusive_node *node, void *type);
void savetxt(intrusive_node *node, void *type);
#endif

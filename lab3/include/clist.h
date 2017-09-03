#ifndef __CLIST_H__
#define __CLIST_H__
#include<stdio.h>
typedef struct intrusive_node intrusive_node_t;
typedef struct intrusive_list intrusive_list_t;
typedef struct position_node position_node_t;

struct intrusive_node {
    struct intrusive_node *next;
    struct intrusive_node *prev;
};

struct intrusive_list {
    intrusive_node_t *head;
};

void init_list(intrusive_list_t *mylist);
void add_node(intrusive_list_t *mylist, intrusive_node_t *n);
void remove_node(intrusive_list_t *mylist, intrusive_node_t *n);
int get_length(intrusive_list_t *mylist);
#endif



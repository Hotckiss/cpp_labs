#include "../include/clist.h"

void init_list(intrusive_list_t *mylist) {
    mylist->head = NULL;
}

void add_node(intrusive_list_t *mylist, intrusive_node_t *n) {
    if (mylist->head == NULL) {
        n->next = n;
        n->prev = n;
        mylist->head = n;
    }
    else {
        n->next = mylist->head->next;
        n->prev = mylist->head;
        mylist->head->next->prev = n;
        mylist->head->next = n;
    }
}
void remove_node(intrusive_list_t *mylist, intrusive_node_t *node) {
    if (node == mylist->head && node->next == node)
        mylist->head = NULL;
    else if (node == mylist->head) {
        mylist->head->prev->next = mylist->head->next;
        mylist->head->next->prev = mylist->head->prev;
        mylist->head = mylist->head->prev;
    }
    else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
}

int get_length(intrusive_list_t *mylist) {
    int len = 0, flag = 1;
    if (mylist->head == NULL)
        return len;
    intrusive_node_t *p = mylist->head;
    while (flag) {
        if (p->next == mylist->head)
            flag = 0;
        len++;
        p = p->next;
    }
    return len;
}

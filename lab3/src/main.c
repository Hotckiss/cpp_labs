#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include "../include/clist.h"
#define container_of(ptr, type, member) (type*)( (char*)(ptr) - offsetof(type, member))
struct position_node {
    int x, y;
    intrusive_node_t node;
};
void remove_position(intrusive_list_t *mylist, int x, int y)
{
    if (mylist->head == NULL)
        return;
    intrusive_node_t *p = mylist->head;
    position_node_t *val;
    while (1) {
        val = container_of(p, position_node_t, node);
        if (val->x == x && val->y == y) {
            remove_node(mylist, p);
            p = p->next;
            free(val);
        }
        else
            p = p->next;
        if (mylist->head == NULL)
            break;
        if (p == mylist->head) {
            val = container_of(p, position_node_t, node);
            if (val->x == x && val->y == y) {
                remove_node(mylist, p);
                free(val);
            }
            break;
        }
    }
}
void add_position(intrusive_list_t *mylist, int x, int y)
{
    position_node_t *new_pos = (position_node_t *)malloc(sizeof(position_node_t));
    new_pos->x = x;
    new_pos->y = y;
    add_node(mylist, &(new_pos->node));
}

void show_all_positions(intrusive_list_t *mylist)
{
    if (mylist->head == NULL) {
        printf("\n");
        return;
    }
    intrusive_node_t *p = mylist->head->next;
    position_node_t *val;
    while (1) {
        val = container_of(p, position_node_t, node);
        printf("(%i %i) ", val->x, val->y);
        if (p == mylist->head)
            break;
        p = p->next;
    }
    printf("\n");
}
void remove_all(intrusive_list_t *mylist) {
    if (mylist->head == NULL)
        return;
    intrusive_node_t *p = mylist->head;
    position_node_t *val;
    while (1) {
        val = container_of(p, position_node_t, node);
        remove_node(mylist, p);
        p = p->next;
        free(val);
        if (mylist->head == NULL)
            break;
        if (p == mylist->head) {
            val = container_of(p, position_node_t, node);
            remove_node(mylist, p);
            free(val);
            break;
        }
    }
}
int main() {
    intrusive_list_t mylist;
    char command[100];
    char c;
    int x, y, flag = 1, cur = 0, flag_s;
    init_list(&mylist);
    while (flag) {
        flag_s = 1;
        while (flag_s) {
            c = getchar();
            if (c == ' ' || c == '\n') {
                flag_s = 0;
                command[cur] = '\0';
            }
            else {
                command[cur] = c;
                cur++;
            }
        }
        if (strcmp(command, "exit") == 0) {
            remove_all(&mylist);
            flag = 0;
        }
        else if (strcmp(command, "add") == 0) {
            scanf("%i%i", &x, &y);
            add_position(&mylist, x, y);
        }
        else if (strcmp(command, "rm") == 0) {
            scanf("%i%i", &x, &y);
            remove_position(&mylist, x, y);
        }
        else if (strcmp(command, "print") == 0) {
            show_all_positions(&mylist);
        }
        else if (strcmp(command, "rma") == 0) {
            remove_all(&mylist);
        }
        else if (strcmp(command, "len") == 0) {
            printf("%i\n", get_length(&mylist));
        }
        else
            printf("Unknown command\n");
        if (c != '\n')
            flag_s = 1;
        while (flag_s) {
            c = getchar();
            if (c == '\n')
                flag_s = 0;
        }
        cur = 0;
    }
    return 0;
}

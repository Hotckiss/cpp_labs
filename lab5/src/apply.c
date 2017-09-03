#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/apply.h"
#include "../include/position.h"
void count(intrusive_node* node, void *cnt) {
    (*(int *)cnt)++;
}

void print(intrusive_node *node, void *format) {
    position_node *node1 = (position_node *)get_position(node);
    printf((char *)format, node1->x, node1->y);
}
void loadbin(intrusive_list *list, char *finname) {
    FILE *f = fopen(finname, "rb");
    int x = 0, y = 0;
    while (!feof(f)) {
        x = 0;
        y = 0;
        fread(&x, 3, 1, f);
        fread(&y, 3, 1, f);
        if ((x & (1 << 23)) > 0) {
            x = x | (255 << 24);
            x = ~x;          
            x++;
            x = -x;
        }
        if ((y & (1 << 23)) > 0) {
            y = y | (255 << 24);
            y = ~y;
            y++;
            y = -y;
        }
        if (!feof(f))
            add_position(list, x, y);
    }
    fclose(f);
}

void loadtxt(intrusive_list *list, char *finname) {
    int x, y;
    FILE *f = fopen(finname, "rt");
    while (fscanf(f, "%d %d", &x, &y) == 2)
        add_position(list, x, y);
    fclose(f);
}
void savetxt(intrusive_node *node, void *type) {
    position_node *node1 = (position_node *)get_position(node);
    fprintf((FILE *)type, "%d %d\n", node1->x, node1->y);
}

void savebin(intrusive_node *node, void *type) {
    position_node *node1 = (position_node *)get_position(node);
    fwrite(&node1->x, 3, 1, (FILE *)type);
    fwrite(&node1->y, 3, 1, (FILE *)type);
}

#include<stdbool.h>
#include<stddef.h>

#include "red_black_node.h"

t_rb_node *ft_rbtnew(void *content) {
    t_rb_node *node;

    node = malloc(sizeof(t_rb_node));
    if (!node)
        return NULL;

    node->content = content;
    node->color = RED;
    node->left = false;
    return node;
}
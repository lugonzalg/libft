#include <stdbool.h>
#include <stdlib.h>

#include "include/libft.h"

t_tree_node *ft_tree_node_new(void *content) {
    t_tree_node *node;

    node = ft_calloc(1, sizeof(t_tree_node));
    if (!node)
        return NULL;

    node->content = content;
    return node;
}
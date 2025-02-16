#include <stdlib.h>

#include "include/libft.h"

void    ft_tree_node_delone(t_tree_node *node, void (*del)(void *)) {

    del(node->content);
    free(node);
}
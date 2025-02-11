#include <stdbool.h>

#include "include/libft.h"


static void __tree_node_insert(t_tree_node *root, t_tree_node* new_node, t_compare (*compare)(void *a, void *b)) {

    // root > new_node
    if (compare(root->content, new_node->content) == GREATER) {
        
        if (!root->left)
            root->left = new_node;
        else
            __tree_node_insert(root->left, new_node, compare);
    }
    // root <= new_node
    else {
        if (!root->right)
            root->right = new_node;
        else
            __tree_node_insert(root->right, new_node, compare);
    }

}

void    ft_tree_node_insert(t_tree_node **root, t_tree_node* new_node, t_compare (*compare)(void *a, void *b)) {

    if (*root == NULL)
        *root = new_node;
    else
        __tree_node_insert(*root, new_node, compare);
}
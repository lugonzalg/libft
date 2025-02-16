#include "include/libft.h"

/*
    Using t_compare {-1, 0, 1} where the user must implement its onw function
    for comparison, it will be used for {LESS, EQUAL, MORE}

    When deleting a node from the tree, we face 3 cases:
     1 - delete a node: not that easy, delete an recompensate the tree
     2 - delete a leaf: easy delete a leaf
     3 - not found: easy do nothing

*/

t_tree_node *__find_min(t_tree_node *node) {
    while (node && node->left)
        node = node->left;
    return node;
}

t_tree_node *ft_tree_node_delete(
    t_tree_node *root,
    void *content,
    t_compare (*compare) (void *a, void *b),
    void (*del)(void *)
) {
    t_compare   comparison;
    t_tree_node *tmp;

    if (root == NULL)
        return NULL;

    comparison = compare(root->content, content);
    // the node is lower than the root, has to trasverse through the left (min)
    if (comparison == LESS) {
        root->left = ft_tree_node_delete(root->left, content, compare, del);
    }
    // the node is higher than the root, has to trasverse through the right (max)
    else if (comparison == GREATER) {
        root->right = ft_tree_node_delete(root->right, content, compare, del);
    }
    // the node is equal to the root
    else {
        // there is no child node, is a leaf 
        if (root->left == NULL && root->right == NULL) {
            ft_tree_node_delone(root, del);
            return NULL;
        }
        // there is no left child
        else if (root->left == NULL) {
            tmp = root->right;
            ft_tree_node_delone(root, del);
            return tmp;
        }
        // there is no right child
        else if (root->right == NULL) {
            tmp = root->left;
            ft_tree_node_delone(root, del);
            return tmp;
        }
        // root has both childs, find the minimun
        else {
            tmp = __find_min(root->right);
            del(root->content);
            root->content = tmp->content;
            root->right = ft_tree_node_delete(
                root->right, 
                tmp, 
                compare, 
                del
            );
        }
    }
    return root;
}
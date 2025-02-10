#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef enum e_color {
    RED = 0,
    BLACK
}   t_color;

typedef struct s_rb_node {
    t_rb_node   *left;
    t_rb_node   *right;
    t_rb_node   *parent;

    t_color     color;
    bool        is_left;
}   t_rb_node;

#endif //RED_BLACK_TREE_H
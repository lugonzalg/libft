#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

typedef enum e_compare {
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
}   t_compare;

typedef struct s_tree_node {
    void                *content;

    struct s_tree_node  *left;
    struct s_tree_node  *right;
}   t_tree_node;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef bool (*c_compare)(void *v1, int low, int high);

void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//RB TREE
t_tree_node	*ft_tree_node_new(void *content);
void		ft_tree_node_insert(t_tree_node **root, t_tree_node* new_node, t_compare (*compare)(void *a, void *b));
t_tree_node *ft_tree_node_delete(t_tree_node *root, void *content, t_compare (*compare) (void *a, void *b), void (*del)(void *));
void        ft_tree_node_delone(t_tree_node *node, void (*del)(void*));
void		ft_tree_node_clear(t_tree_node *root, void (*del)(void *));

// MERGE SORT
void merge(void *array, int low, int mid, int high, size_t nbytes, c_compare compare);
void merge_sort(void *vector, int low, int high, size_t nbytes, c_compare compare);

#endif
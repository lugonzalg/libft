#include <stdlib.h>

#include "include/libft.h"

void ft_merge(
    void        *array, 
    int         low, 
    int         mid, 
    int         high, 
    size_t      nbytes,
    c_compare   compare
    ) {

    void*   tmp_vector;
    int     idx_low;
    int     idx_mid;
    int     idx;

    idx = 0;
    idx_low = low;
    idx_mid = mid + 1;
    tmp_vector = (void *)malloc(nbytes * (high - low + 1));
    if (tmp_vector == NULL)
        return ;

    while (idx_low <= mid && idx_mid <= high) {
        if (compare(array, idx_low, idx_mid)) {
            ft_memmove(tmp_vector + (idx * nbytes), array + (idx_low * nbytes), nbytes);
            idx_low ++;
        }
        else {
            ft_memmove(tmp_vector + (idx * nbytes), array + (idx_mid * nbytes), nbytes);
            idx_mid++;
        }
        idx++;
    }

    while (idx_low <= mid) {
        ft_memmove(tmp_vector + (idx * nbytes), array + (idx_low * nbytes), nbytes);
        idx_low++;
        idx++;
    }

    while (idx_mid <= high) {
        ft_memmove(tmp_vector + (idx * nbytes), array + (idx_mid * nbytes), nbytes);
        idx_mid++;
        idx++;
    }
    
    ft_memmove(array + low * nbytes, tmp_vector, (high - low + 1) * nbytes);
    free(tmp_vector);

}

// https://www.geeksforgeeks.org/merge-sort-with-o1-extra-space-merge-and-on-lg-n-time/
// https://www.geeksforgeeks.org/merge-sort/
void ft_merge_sort(
    void        *array, 
    int         low, 
    int         high, 
    size_t      nbytes, 
    c_compare   compare
) {
    size_t mid;

    if (low < high) {
        mid = (low + high) / 2;
        ft_merge_sort(array, low, mid, nbytes, compare);
        ft_merge_sort(array, mid + 1, high, nbytes, compare);
        ft_merge(array, low, mid, high, nbytes, compare);
    }
}

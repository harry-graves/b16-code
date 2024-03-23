#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    if (!tree || !left(tree))
    {
        return tree;
    }
    return bst_min(left(tree));
}

template <typename T> T bst_max(const T &tree)
{
    if (!tree || !right(tree))
    {
        return tree;
    }
    return bst_max(right(tree));
}

#endif // __binary_saerch_tree_enhanced__
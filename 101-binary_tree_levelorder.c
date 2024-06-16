#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, return 0, else return depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree && tree->parent)
    {
        depth++;
        tree = tree->parent;
    }
    return (depth);
}

/**
 * binary_trees_ancestor - Finds the LCA of two nodes
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors, return NULL, else return the CA.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t depth_first, depth_second;

    if (!first || !second)
        return (NULL);

    depth_first = binary_tree_depth(first);
    depth_second = binary_tree_depth(second);

    while (depth_first > depth_second)
    {
        first = first->parent;
        depth_first--;
    }
    while (depth_second > depth_first)
    {
        second = second->parent;
        depth_second--;
    }

    while (first && second)
    {
        if (first == second)
            return ((binary_tree_t *)first);
        first = first->parent;
        second = second->parent;
    }

    return (NULL);
}

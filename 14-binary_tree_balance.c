#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node != NULL && node->left == NULL && node->right == NULL)
        return (1);
    return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t alpha, beta;

    if (tree == NULL)
        return (0);

    alpha = binary_tree_height(tree->left);
    beta = binary_tree_height(tree->right);

    if (alpha >= beta)
        return (1 + alpha);

    return (1 + beta);
}

/**
 * binary_tree_balance - measures the balance factor of a tree
 * @tree: pointer to the root node to measure the balance factor
 *
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int alpha, beta;

    if (tree == NULL)
        return (0);

    alpha = binary_tree_height(tree->left);
    beta = binary_tree_height(tree->right);

    return (alpha - beta);
}

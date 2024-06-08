#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node to measure the height.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t lefite, rightie;
    
    if (!tree)
        return (0);

    leftie = binary_tree_height(tree->left);
    rightie = binary_tree_height(tree->right);

    return (1 + ((leftie > rightie) ? leftie : rightie));
}

/**
 * binary_tree_balance - Measures the balance factor of a tree.
 * @tree: A pointer to the root node to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int leftie, rightie;
    
    if (!tree)
        return (0);

    leftie = binary_tree_height(tree->left);
    rightie = binary_tree_height(tree->right);

    return (leftie - rightie);
}

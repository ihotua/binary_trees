#include "binary_trees.h"

/**
 * binary_tree_balance - This measures the balance factor.
 * @tree: A pointer to the root node to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) -
				binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - This measures the height of a binary tree.
 * @tree: A pointer to the root node to measure the height.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
	    size_t leftie = 0, rightie = 0;

	    leftie = tree->left ? 1 +
		binary_tree_height(tree->left) : 1;
	    rightie = tree->right ? 1 +
		binary_tree_height(tree->right) : 1;
	    return ((leftie > rightie) ? leftie : rightie);
	}
}

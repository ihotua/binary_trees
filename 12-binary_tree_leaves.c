#include "binary_trees.h"

/**
 * binary_tree_leaves - This counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t numb_l = 0;

	if (tree)
	{
		numb_l += (!tree->left && !tree->right) ? 1 : 0;
		numb_l += binary_tree_leaves(tree->left);
		numb_l += binary_tree_leaves(tree->right);
	}
	return (numb_l);
}

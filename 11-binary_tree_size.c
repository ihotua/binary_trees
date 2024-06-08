#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t meas = 0;

	if (tree)
	{
		meas += 1;
		meas += binary_tree_size(tree->left);
		meas += binary_tree_size(tree->right);
	}
	return (meas);
}

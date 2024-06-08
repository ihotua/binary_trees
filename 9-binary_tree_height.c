#include "binary_trees.h"

/**
 * binary_tree_height - This measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t j = 0, k = 0;

		j = tree->left ? 1 +
			binary_tree_height(tree->left) : 0;
		k = tree->right ? 1 +
			binary_tree_height(tree->right) : 0;
		return ((j > k) ? j : k);
	}
	return (0);
}

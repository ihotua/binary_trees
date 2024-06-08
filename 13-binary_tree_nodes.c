#include "binary_trees.h"

/**
 * binary_tree_nodes - This counts the nodes with at least 1 child.
 * @tree: A pointer to the root node of the tree.
 * Return: If tree is NULL, return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count += (tree->left || tree->right) ? 1 : 0;
		count += binary_tree_nodes(tree->left);
		count += binary_tree_nodes(tree->right);
	}
	return (count);
}

#include "binary_trees.h"

/**
 * binary_tree_is_leaf - The function checks if a node is a leaf
 * @node: The pointer to the node to check.
 *
 * Return: Return 0 if it's not a leaf, else 1.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}

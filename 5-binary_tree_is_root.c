#include "binary_trees.h"

/**
 * binary_tree_is_root - This function checks if node is a root.
 * @node: The node to check.
 *
 * Return: Returns 1 if thee node is a root, else 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}

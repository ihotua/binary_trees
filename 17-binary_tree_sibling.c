#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a tree
 * @node: A pointer to the node to find the sibling.
 *
 * Return: If node is NULL or no sibling,else a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}

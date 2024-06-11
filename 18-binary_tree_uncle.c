#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncl
 *
 * Return: Pointer to the uncle node, or NULL if NULL or has uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	binary_tree_t *grandparent = node->parent->parent;
	binary_tree_t *parent = node->parent;

	if (grandparent->left == parent)
		return (grandparent->right);
	return (grandparent->left);
}

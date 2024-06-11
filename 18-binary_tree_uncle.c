#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncl
 *
 * Return: Pointer to the uncle node, or NULL if NULL or has uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
	{
		return (NULL);
	}
	
	binary_tree_t *grandparent;
	
	grandparent = node->parent->parent;

	if (grandparent == NULL)
	{
		return (NULL);
	}

	if (node->parent == grandparent->left)
	{
		return grandparent->right;
	}
	else
	{
		return grandparent->left;
	}
}

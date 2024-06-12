#include "binary_trees.h"

/**
 * binary_tree_sibling - This finds the sibling of a node
 * @node: A pointer to the node to find the sibling
 * Return: A pointer to the sibling node, else return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->right)
		return (node->parent->left);
	return (node->parent->right);
}

/**
 * binary_tree_uncle - This finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 * Return: A pointer to the uncle node, else return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}

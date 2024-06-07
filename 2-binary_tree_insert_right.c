#include "binary_trees.h"

/**
 * binary_tree_insert_right - Adds a binary tree node on the right
 * @parent: Parent node to insert the right-child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL if an error occurs 
 */

 binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}

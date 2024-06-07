#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a binary tree node to the left
 * @parent: Parent node to add the new node to
 * @value: Value of new node
 *
 * Return: Pointer to the new node, or NULL when an error occurs
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}

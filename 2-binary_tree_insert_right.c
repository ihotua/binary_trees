#include "binary_trees.h"

/**
 * binary_tree_insert_right - Adds a binary tree node on the right
 * @parent: Parent node to insert the right-child in.
 * @value: Value to store in the new node.
 * Return: Pointer to the new node, or NULL if an error occurs 
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent,
		int value)
{
	if (parent == NULL)
		return (NULL);
	
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	      	return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
		parent->right = new_node;
	}
	parent->right = new_node;
	new_node->right = NULL;

	return (new_node);
}

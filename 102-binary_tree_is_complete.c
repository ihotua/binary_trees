#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates right the binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *mike;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	mike = tree->left;
	tree->left = mike->right;
	if (mike->right != NULL)
		mike->right->parent = tree;

	mike->right = tree;
	mike->parent = tree->parent;
	tree->parent = mike;

	if (mike->parent != NULL)
	{
		if (mike->parent->left == tree)
			mike->parent->left = mike;
		else
			mike->parent->right = mike;
	}

	return (mike);
}

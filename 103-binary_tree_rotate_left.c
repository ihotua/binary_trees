#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs left-rotation on binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *fresh_root, *part;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	
	fresh_root = tree->right;
	part = fresh_root->left;

	fresh_root->left = tree;
	tree->right = part;

	if (part != NULL)
		part->parent = tree;

	fresh_root->parent = tree->parent;
	tree->parent = fresh_root;

	return (fresh_root);
}

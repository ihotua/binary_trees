#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	return (1 + (l > r ? l : r));
}

/**
 * is_avl_balanced - Auxiliary function to check if a tree is AVL balanced.
 * @tree: Pointer to the root node of the tree to check.
 * @lower: Lower bound value for nodes in the subtree.
 * @high: Upper bound value for nodes in the subtree.
 *
 * Return: 1 if tree is AVL balanced, 0 otherwise.
 */
int is_avl_balanced(const binary_tree_t *tree, int lower, int high)
{
	size_t height_l, height_r, balance_factor;

	if (tree == NULL)
		return (1);

	if (tree->n <= lower || tree->n >= high)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	balance_factor = height_l > height_r ? height_l - height_r : height_r - height_l;

	if (balance_factor > 1)
		return (0);

	return (is_avl_balanced(tree->left, lower, tree->n) &&
		is_avl_balanced(tree->right, tree->n, high));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is AVL, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_balanced(tree, INT_MIN, INT_MAX));
}

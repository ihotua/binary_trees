#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_is_full - checks if  tree is full
 * @tree: pointer to the root node
 *
 * Return: 1 if full, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int leftie, rightie;

	if (tree == NULL)
		return (0)
	if (binary_tree_is_leaf(tree))
		return (1);

	leftie = binary_tree_is_full(tree->left)
	rightie = binary_tree_is_full(tree->right));

	return (0);
}

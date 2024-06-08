#include "binary_trees.h"

/**
 * binary_tree_balance - This measures the balance factor.
 * @tree: A pointer to the root node to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (0);

	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));

}

/**
 * binary_tree_height - This measures the height of a binary tree.
 * @tree: A pointer to the root node to measure the height.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
	    return(-1)


	size_t leftie = tree->left ? 1 +
		binary_tree_height(tree->left) : 1;
	size_t rightie = tree->right ? 1 +
		binary_tree_height(tree->right) : 1;


	return (1 + ((leftie > rightie) ? leftie : rightie));
}

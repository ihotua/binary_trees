#include "binary_trees.h"

/**
 * bst_insert - This inserts nodes to create a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *fresh;

	if (tree != NULL)
	{
		temp = *tree;

		if (temp == NULL)
		{
			fresh = binary_tree_node(temp, value);
			if (fresh == NULL)
				return (NULL);
			return (*tree = fresh);
		}

		if (value < temp->n)
		{
			if (temp->left != NULL)
				return (bst_insert(&temp->left, value));

			fresh = binary_tree_node(temp, value);
			if (fresh == NULL)
				return (NULL);
			return (temp->left = fresh);
		}
		if (value > temp->n)
		{
			if (temp->right != NULL)
				return (bst_insert(&temp->right, value));

			fresh = binary_tree_node(temp, value);
			if (fresh == NULL)
				return (NULL);
			return (temp->right = fresh)
		}
	}
	return (NULL);
}

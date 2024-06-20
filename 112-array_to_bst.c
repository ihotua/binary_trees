#include "binary_trees.h"

/**
 * array_to_bst - This builds a BST from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t x;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		bst_insert(&root, array[x]);
	}

	return (root);
}

#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	size_t l = tree->left ? 1 +
		binary_tree_height(tree->left) : 0;
	size_t r = tree->right ? 1 +
		binary_tree_height(tree->right) : 0;
	return ((l > r) ? l : r);
}

/**
 * binary_tree_depth - Measures the depth of a node
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: The depth of the node. If tree is NULL, return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 +
			binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - this function makes a linked list
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new_node, *other;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = level;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		other = *head;
		while (other->next != NULL)
		{
			other = other->next;
		}
		new_node->next = NULL;
		other->next = new_node;
	}
}

/**
 * recursion - goes through the complete tree and stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *other;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			other = head;
			while (other != NULL)
			{
				if (count == other->n)
				{
					func(other->node->n);
				}
				other = other->next;
			}
			count++;
		}
		while (head != NULL)
		{
			other = head;
			head = head->next;
			free(other);
		}
	}
}

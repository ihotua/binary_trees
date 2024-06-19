#include "binary_trees.h"

/**
 * create_queue_node - Creates a new queue_node_t node.
 * @tree_node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL. Else, a pointer to the new node */
queue_node_t *create_queue_node(binary_tree_t *tree_node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->tree_node = tree_node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a queue_node_t queue.
 * @queue: A pointer to the front of the queue.
 */
void free_queue(queue_node_t *queue)
{
	queue_node_t *temp;

	while (queue != NULL)
	{
		temp = queue->next;
		free(queue);
		queue = temp;
	}
}

/**
 * enqueue - Adds a node to the end of a queue_node_t queue.
 * @tree_node: The binary tree node to add.
 * @queue: A pointer to the front of the queue.
 * @rear: A double pointer to the rear of the queue.
 *
 */
void enqueue(binary_tree_t *tree_node, queue_node_t *queue, queue_node_t **rear)
{
	queue_node_t *new_node;

	new_node = create_queue_node(tree_node);
	if (new_node == NULL)
	{
		free_queue(queue);
		exit(1);
	}
	(*rear)->next = new_node;
	*rear = new_node;
}

/**
 * dequeue - Removes the front node from a queue_node_t queue.
 * @queue: A double pointer to the front of the queue.
 */
void dequeue(queue_node_t **queue)
{
	queue_node_t *temp;

	temp = (*queue)->next;
	free(*queue);
	*queue = temp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0. Else, 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_node_t *front, *rear;
	unsigned char end_flag = 0;

	if (tree == NULL)
		return (0);

	front = rear = create_queue_node((binary_tree_t *)tree);
	if (front == NULL)
		exit(1);

	while (front != NULL)
	{
		if (front->tree_node->left != NULL)
		{
			if (end_flag == 1)
			{
				free_queue(front);
				return (0);
			}
			enqueue(front->tree_node->left, front, &rear);
		}
		else
		{
			end_flag = 1;
		}

		if (front->tree_node->right != NULL)
		{
			if (end_flag == 1)
			{
				free_queue(front);
				return (0);
			}
			enqueue(front->tree_node->right, front, &rear);
		}
		else
		{
			end_flag = 1;
		}

		dequeue(&front);
	}
	return (1);
}
